// Fill out your copyright notice in the Description page of Project Settings.


#include "StoryMng.h"
#include "Story.h"

#include "AreaOverride.h"
#include "PartyHandle.h"

#include "Blue.h"

namespace Manager
{
	ACosmNexus* Story = NULL;
}

ACosmNexus::ACosmNexus() : ANexus(){}

ACosmNexus* ACosmNexus::Get()
{
	return Manager::Story;
}

void ACosmNexus::GetStoryMngBP(ACosmNexus*& StoryMng)
{
	StoryMng = Manager::Story;
}

void ACosmNexus::BeginPlay()
{

#if UE_BUILD_DEVELOPMENT
	/**
	FBlueEnsureImplementation BEF = FBlueEnsureImplementation();
	BEF.Add("InitBP");
	BEF.Add("PreStartBP");
	BEF.Add("PostStartBP");
	BEF.Go(this, ID.ToString());
	*/
#endif

	Manager::Story = this;
	Log.Write(AAUTH,LNORM,VNONE,1,0, "Init()");
	bInit = true;
	OnInitComplete.Broadcast(this);
		
}




void ACosmNexus::StartStory(UStory* InStory)
{
	ActiveStory = InStory;
	Log.Write(AAUTH, LNORM, VNONE, 1, 0, "Story has been started: " + FString::FromInt(ActiveStory->Key));
	ActiveStory->PreStart();
	LoadParty(&ActiveStory->Party);

}












void ACosmNexus::StartGame()
{
	StartGameBP();

	if (ActiveStory == NULL)
	{
		Log.Write(AAUTH, LCRIT, VNONE, 1, 0, "No Active Story was set when StartStory was called.");
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "No Active Story was set when StartStory was called.");
	}
	else
	{
		StartStory(ActiveStory);
	}
}






void ACosmNexus::ChangeArea(UArea* NextArea, FAddress NextAddress)
{
	PendingAreaAddress = FAreaAddress(NextArea, NextAddress);

	if (AreaAddress.IsValid())
	{
		AreaAddress.Area->OnUnloaded.AddDynamic(this, &ACosmNexus::AreaUnloaded);
		AreaAddress.Area->Unload();
	}
	else
	{
		AreaUnloaded();
	}
}

void ACosmNexus::AreaUnloaded()
{

	AreaAddress = PendingAreaAddress;
	PendingAreaAddress.Invalidate();
	AreaAddress.Area->Enter(AreaAddress.Address);
}

void ACosmNexus::LoadZone(FZone* Zone)
{


	FLatentActionInfo LatentInfo;
	LatentInfo.CallbackTarget = this;
	LatentInfo.ExecutionFunction = "MapLoaded";
	UGameplayStatics::LoadStreamLevelBySoftObjectPtr(this, Zone->Level, true, false, LatentInfo);


	//StreamedDynamic = ULevelStreamingDynamic::LoadLevelInstanceBySoftObjectPtr(this, NextMap, FVector(0.0f), FRotator(0.0f), bFound);
	//StreamedDynamic->OnLevelLoaded.AddDynamic(this, &UArea::MapLoaded);
}





void ACosmNexus::LoadParty(FParty* InActiveParty)
{
	Log.Write(AAUTH, LNORM, VNONE, 1, 0, "Loading Party.");
	ActiveParty = InActiveParty;

	ActivePartyHandle = NewObject<UPartyHandle>(this, UPartyHandle::StaticClass());
	ActivePartyHandle->OnLoadComplete.AddDynamic(this, &ACosmNexus::StartStoryLoadPartyComplete);
	ActivePartyHandle->Init(ActiveParty);
	ActivePartyHandle->BufferActra();

}

void ACosmNexus::StartStoryLoadPartyComplete()
{

	Log.Write(AAUTH, LNORM, VNONE, 1, 0, "Loading Party Complete.");

	UAreaOverride* AreaOverride = NewObject<UAreaOverride>(this, UAreaOverride::StaticClass());
	ActiveStory->PostStart(AreaOverride);

	ACosmNexus* AreaMng = ACosmNexus::Get();

	if (AreaOverride->IsActive())
	{
		Log.Write(AAUTH, LNORM, VNONE, 1, 0, "Area Override is Active.");
		ChangeArea(AreaOverride->Area_, AreaOverride->Address_);
	}

	AreaOverride->ConditionalBeginDestroy();

}

void ACosmNexus::EngagePartyBP()
{

}
