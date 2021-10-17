// Fill out your copyright notice in the Description page of Project Settings.


#include "Mem/Area.h"
#include "Mng/AreaMng.h"
#include "Blue.h"

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


void UArea::Init(FLogger* InLog)
{
#if UE_BUILD_DEVELOPMENT 
	FBlueEnsureImplementation BEF = FBlueEnsureImplementation();
	BEF.Add("InitBP");
	BEF.Add("EnterBP");
	BEF.Go(this, ID.ToString());
#endif

	Log = InLog;

	InitBP();
	OnInitComplete.Broadcast(this);

	/**
	SoftServe = NewObject<USoftServe>(this, USoftServe::StaticClass());
	
	PreSoftServeBP();
	if (SoftServe->HasNull())
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "A Zone SoftClass was invalid: " + Key);
	}

	SoftServe->OnComplete.AddDynamic(this, &UArea::PostSS);
	SoftServe->Stream();
	*/
}


/**
void UArea::PostSS(USoftServe* SS)
{
	PostSSBP();
	OnInitComplete.Broadcast(this);
	SoftServe->ConditionalBeginDestroy();
	SoftServe = NULL;
}

void UArea::AddSoftServe(TSoftClassPtr<UObject> SCP)
{
	SoftServe->Add(SCP);
}

*/
void UArea::RegZone(FZone& Zone)
{
	FString StringID = Zone.ID.ToString();
	Log->Write(AAUTH, LNORM, VNONE, 1, 0, "Registering Zone: "+StringID);
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
	AAreaMng* AreaMng = AAreaMng::Get();
	AreaMng->LoadZone(ActiveZone);
}