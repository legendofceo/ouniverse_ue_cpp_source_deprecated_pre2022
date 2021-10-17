// Fill out your copyright notice in the Description page of Project Settings.


#include "Lib.h"
#include "Engine/StreamableManager.h"
#include "Engine/AssetManager.h"
#include "Blue.h"

ULib::ULib()
{

}

void ULib::SetID(FString InID)
{
	ID = InID;
}

void ULib::Init()
{	
#if UE_BUILD_DEVELOPMENT 
	FBlueEnsureImplementation BEF = FBlueEnsureImplementation();
	BEF.Add("PreSSBP");
	BEF.Add("PostSSBP");
	BEF.Add("PostInitBP");
	BEF.Go(this, ID);
#endif

	Log.W("Init()").UE();

	PreSSBP();

	TArray<FSoftObjectPath> ItemsToStream;
	FStreamableManager& Streamable = UAssetManager::GetStreamableManager();

	for (TSoftClassPtr<UObject> SoftClass : SoftClasses)
	{
		ItemsToStream.AddUnique(SoftClass.ToSoftObjectPath());
	}

	if (ItemsToStream.Num() == 0)
	{
		Log.W("No SoftClasses were registered (Lib | "+ID+")").Type(TCRIT).DM().UE();
	}
	else
	{
		Log.W("Loading SoftClass. Registered: " + FString::FromInt(ItemsToStream.Num())).UE();
		Streamable.RequestAsyncLoad(ItemsToStream, FStreamableDelegate::CreateUObject(this, &ULib::PostSS));
	}
}

void ULib::PostInit()
{

}

void ULib::RegSCP(TSoftClassPtr<UObject> StoryClass)
{
	if (StoryClass.IsNull())
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "A SoftClass was NULL! "+ID);
		Log.W("A SoftClass was NULL!").UE();
	}
	SoftClasses.Add(StoryClass);
}

void ULib::Complete()
{
	Log.W("InitComplete. Calling OnInitComplete Delegate.").UE();
	bInit = true;
	OnInitComplete.Broadcast(this);
}