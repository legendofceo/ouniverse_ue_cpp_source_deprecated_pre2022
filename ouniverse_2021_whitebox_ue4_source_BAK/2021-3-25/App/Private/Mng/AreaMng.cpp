// Fill out your copyright notice in the Description page of Project Settings.


#include "Mng/AreaMng.h"
#include "Engine/StreamableManager.h"
#include "Engine/AssetManager.h"


UAreaMng::UAreaMng()
{

	PrimaryComponentTick.bCanEverTick = false;

}



void UAreaMng::BeginPlay()
{
	Super::BeginPlay();

}



void UAreaMng::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}





void UAreaMng::DoChangeArea(FAreaAddress NextArea)
{
	PendingAreaAddress = NextArea;

	if (Area != NULL)
	{
		Area->OnUnloaded.AddDynamic(this, &UAreaMng::AreaUnloaded);
		Area->Unload();
	}
	else
	{
		AreaUnloaded();
	}

}

void UAreaMng::AreaUnloaded()
{
	if (PendingAreaAddress.IsValid())
	{
		//Doing this incase asynch load finished in same thread:
		FSoftObjectPath SoftObjectPath = PendingAreaAddress.Area.ToSoftObjectPath();
		FStreamableManager& Streamable = UAssetManager::GetStreamableManager();
		Streamable.RequestAsyncLoad(PendingAreaAddress.Area.ToSoftObjectPath(), FStreamableDelegate::CreateUObject(this, &UAreaMng::LoadNextArea));
	}
}

void UAreaMng::LoadNextArea()
{
	AreaAddress = PendingAreaAddress;
	PendingAreaAddress.Invalidate();
	Area = NewObject<UArea>(this, AreaAddress.Area.Get());
	Area->Load(AreaAddress.Address);
}
