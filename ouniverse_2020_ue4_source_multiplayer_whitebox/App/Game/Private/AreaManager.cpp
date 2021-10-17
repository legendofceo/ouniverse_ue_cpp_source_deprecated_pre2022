// Fill out your copyright notice in the Description page of Project Settings.


#include "AreaManager.h"
#include "Kismet/GameplayStatics.h"

UAreaManager::UAreaManager() : UManager()
{

}

void UAreaManager::Init()
{

#if (!UE_BUILD_SHIPPING)
	/**
	FBlueEnsureImplementation BEF = FBlueEnsureImplementation();
	BEF.Add("InitBP");
	BEF.Add("PreStartBP");
	BEF.Add("PostStartBP");
	BEF.Go(this, ID.ToString());
	*/
#endif
	
	InitComplete();
}


void UAreaManager::ChangeArea(UArea* NextArea, FAddress NextAddress)
{
	PendingAreaAddress = FAreaAddress(NextArea, NextAddress);

	if (AreaAddress.IsValid())
	{
		AreaAddress.Area->OnUnloaded.AddDynamic(this, &UAreaManager::AreaUnloaded);
		AreaAddress.Area->Unload();
	}
	else
	{
		AreaUnloaded();
	}
}

void UAreaManager::AreaUnloaded()
{

	AreaAddress = PendingAreaAddress;
	PendingAreaAddress.Invalidate();
	AreaAddress.Area->Enter(AreaAddress.Address);
}

void UAreaManager::LoadZone(FZone* Zone)
{


	FLatentActionInfo LatentInfo;
	LatentInfo.CallbackTarget = this;
	LatentInfo.ExecutionFunction = "MapLoaded";
	UGameplayStatics::LoadStreamLevelBySoftObjectPtr(this, Zone->Level, true, false, LatentInfo);


	//StreamedDynamic = ULevelStreamingDynamic::LoadLevelInstanceBySoftObjectPtr(this, NextMap, FVector(0.0f), FRotator(0.0f), bFound);
	//StreamedDynamic->OnLevelLoaded.AddDynamic(this, &UArea::MapLoaded);
}