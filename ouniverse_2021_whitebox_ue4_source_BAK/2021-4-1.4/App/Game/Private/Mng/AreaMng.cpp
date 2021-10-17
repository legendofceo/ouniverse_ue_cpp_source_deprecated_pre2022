// Fill out your copyright notice in the Description page of Project Settings.


#include "Mng/AreaMng.h"
#include "Area.h"
#include "Kismet/GameplayStatics.h"

namespace Manager
{
	AAreaMng* Area = NULL;
}

AAreaMng::AAreaMng() : AManagerActor() {}

AAreaMng* AAreaMng::Get()
{
	return Manager::Area;
}

void AAreaMng::GetAreaMngBP(AAreaMng*& AreaMng)
{
	AreaMng = Manager::Area;
}

void AAreaMng::BeginPlay()
{
	Manager::Area = this;

	Log.Write(AAUTH, LNORM, VNONE, 1, 0, "Init()");
	bInit = true;
	OnInitComplete.Broadcast(this);

}

void AAreaMng::ChangeArea(UArea* NextArea, FAddress NextAddress)
{
	PendingAreaAddress = FAreaAddress(NextArea,NextAddress);

	if (AreaAddress.IsValid())
	{
		AreaAddress.Area->OnUnloaded.AddDynamic(this, &AAreaMng::AreaUnloaded);
		AreaAddress.Area->Unload();
	}
	else
	{
		AreaUnloaded();
	}
}

void AAreaMng::AreaUnloaded()
{

	AreaAddress = PendingAreaAddress;
	PendingAreaAddress.Invalidate();
	AreaAddress.Area->Enter(AreaAddress.Address);
}

void AAreaMng::LoadZone(FZone* Zone)
{


	FLatentActionInfo LatentInfo;
	LatentInfo.CallbackTarget = this;
	LatentInfo.ExecutionFunction = "MapLoaded";
	UGameplayStatics::LoadStreamLevelBySoftObjectPtr(this, Zone->Level, true, false, LatentInfo);


	//StreamedDynamic = ULevelStreamingDynamic::LoadLevelInstanceBySoftObjectPtr(this, NextMap, FVector(0.0f), FRotator(0.0f), bFound);
	//StreamedDynamic->OnLevelLoaded.AddDynamic(this, &UArea::MapLoaded);
}