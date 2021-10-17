// Fill out your copyright notice in the Description page of Project Settings.


#include "Area.h"
#include "Blue.h"
#include "Log.h"
#include "MythPro.h"

/**
void UArea::DoLoadMap(TSoftObjectPtr<UWorld> NextMap)
{
	//AAppMode::GetAppMode(this)->DoMapStream(NextMap);
	
	
	FLatentActionInfo LatentInfo;
	LatentInfo.CallbackTarget = this;
	LatentInfo.ExecutionFunction = "MapLoaded";
	UGameplayStatics::LoadStreamLevelBySoftObjectPtr(this, NextMap, true, false, LatentInfo);


	//StreamedDynamic = ULevelStreamingDynamic::LoadLevelInstanceBySoftObjectPtr(this, NextMap, FVector(0.0f), FRotator(0.0f), bFound);
	//StreamedDynamic->OnLevelLoaded.AddDynamic(this, &UArea::MapLoaded);
}
*/

const FName UArea::SYS = "AREA";

void UArea::Init()
{
#if (!UE_BUILD_SHIPPING)
	FBlueEnsureImplementation BEF = FBlueEnsureImplementation();
	BEF.Add("InitBP");
	BEF.Add("EnterBP");
	BEF.Go(this, ID.ToString());
#endif

	InitBP();
	OnInitComplete.Broadcast(this);
}

void UArea::RegZone(FZone& Zone)
{
	FString StringID = Zone.ID.ToString();
	LOG.S(SYS).I(ID).W("Registering Zone: "+StringID);
	Marshal.AddObject(StringID, &Zone.Marshal);
	Zones.Add(Zone.ID,&Zone);
}


void UArea::Enter(FAddress InAddress)
{
	EnterBP(InAddress);
}

void UArea::LoadZone(UPARAM(ref) FZone& Zone)
{
	ActiveZone = &Zone;
	UMythPro::Get()->LoadZone(ActiveZone);
}