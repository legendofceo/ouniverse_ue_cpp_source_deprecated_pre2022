// Fill out your copyright notice in the Description page of Project Settings.


#include "Lib.h"
#include "Log.h"
#include "Engine/StreamableManager.h"
#include "Engine/AssetManager.h"
#include "Blue.h"

ULib::ULib()
{

}

void ULib::SetSYS(FName InSYS)
{
	SYS = InSYS;
}

void ULib::Init()
{	
#if (!UE_BUILD_SHIPPING)
	FBlueEnsureImplementation BEF = FBlueEnsureImplementation();
	BEF.Add("PreSSBP");
	BEF.Add("PostSSBP");
	BEF.Add("PostInitBP");
	BEF.Go(this, SYS.ToString());
#endif

	LOG.S(SYS).W("Init()");

	PreSSBP();

	TArray<FSoftObjectPath> ItemsToStream;
	FStreamableManager& Streamable = UAssetManager::GetStreamableManager();

	for (TSoftClassPtr<UObject> SoftClass : SoftClasses)
	{
		ItemsToStream.AddUnique(SoftClass.ToSoftObjectPath());
	}

	if (ItemsToStream.Num() == 0)
	{
		LOG.S(SYS).T(TCRIT).W("No SoftClasses registered").DebugM();
	}
	else
	{
		LOG.S(SYS).W("Loading SoftClass. Registered: " + FString::FromInt(ItemsToStream.Num()));
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
		LOG.S(SYS).T(TCRIT).W("A SoftClass was NULL!").DebugM();
	}
	SoftClasses.Add(StoryClass);
}

void ULib::Complete()
{
	LOG.S(SYS).W("InitComplete. Calling OnInitComplete Delegate.");
	bInit = true;
	OnInitComplete.Broadcast(this);
}