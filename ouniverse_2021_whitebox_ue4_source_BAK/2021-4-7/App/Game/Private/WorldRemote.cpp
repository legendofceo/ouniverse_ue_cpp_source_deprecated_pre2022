// Fill out your copyright notice in the Description page of Project Settings.


#include "WorldRemote.h"
#include "AppController.h"
#include "AreaManager.h"
#include "PartyRemote.h"

#include "Story.h"
#include "Playthrough.h"

#include "AreaOverride.h"
#include "PartyHandle.h"

#include "Blue.h"

#include "WorldPort.h"

namespace Remote
{
	AWorldRemote* World = NULL;
}

AWorldRemote::AWorldRemote() : ARemote()
{
	UWorldPort* WorldPort = NULL;
	for (int i = 0; i < AAppMode::MaxPlayers; i++)
	{
		FString Name = "WorldPort" + FString::FromInt(i);
		WorldPort = CreateDefaultSubobject<UWorldPort>(*Name);
		Ports.Add(WorldPort);
	}
}

AWorldRemote* AWorldRemote::Get()
{
	return Remote::World;
}

void AWorldRemote::GetStoryMngBP(AWorldRemote*& StoryMng)
{
	StoryMng = Remote::World;
}

void AWorldRemote::BeginPlay()
{
	Super::BeginPlay();

#if UE_BUILD_DEVELOPMENT
	/**
	FBlueEnsureImplementation BEF = FBlueEnsureImplementation();
	BEF.Add("InitBP");
	BEF.Add("PreStartBP");
	BEF.Add("PostStartBP");
	BEF.Go(this, ID.ToString());
	*/
#endif

	Remote::World = this;

	if (HasAuthority())
	{
		AreaManager = NewObject<UAreaManager>(this, UAreaManager::StaticClass());

		FVector Location(0.0f, 0.0f, 0.0f);
		FRotator Rotation(0.0f, 0.0f, 0.0f);
		FActorSpawnParameters SpawnInfo;
		SpawnInfo.bNoFail = true;
		PartyRemote = GetWorld()->SpawnActor<APartyRemote>(APartyRemote::StaticClass(), Location, Rotation, SpawnInfo);
		PartyRemote->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);

		Log.Write(AAUTH, LNORM, VNONE, 1, 0, "Init()");
	}

	AAppController::GetAppController(this)->ClientBootTaskComplete(ClientBootTasksEnum::ClientBootTasksWorldRemote);
	
}




void AWorldRemote::EnterWorld()
{
	EnterWorldBP();
	UStory* ActiveStory = UPlaythrough::Get()->GetActiveStory();

	if (ActiveStory == NULL)
	{
		Log.Write(AAUTH, LCRIT, VNONE, 1, 0, "No Active Story was set when StartStory was called.");
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "No Active Story was set when StartStory was called.");
	}
	else
	{
		Log.Write(AAUTH, LNORM, VNONE, 1, 0, "Story has been started: " + FString::FromInt(ActiveStory->Key));
		Tally.Reset();

		ActiveStory->PreStart();
		PartyRemote->Connect(&ActiveStory->Party, &ActiveStory->Raid);
		PartyRemote->SetPartyMode(EPartyMode::EPartyModeParty);
		PartyRemote->OnBufferComplete.AddDynamic(this,&AWorldRemote::EnterWorld_Tally);
		PartyRemote->Buffer(&Tally);
	}
}


void AWorldRemote::EnterWorld_Tally(int TID)
{

	if (Tally.Complete(TID))
	{
		Log.Write(AAUTH, LNORM, VNONE, 1, 0, "EnterWorldTally Complete");

		UStory* ActiveStory = UPlaythrough::Get()->GetActiveStory();

		UAreaOverride* AreaOverride = NewObject<UAreaOverride>(this, UAreaOverride::StaticClass());
		ActiveStory->PostStart(AreaOverride);

		if (AreaOverride->IsActive())
		{
			Log.Write(AAUTH, LNORM, VNONE, 1, 0, "Area Override is Active.");
			AreaManager->ChangeArea(AreaOverride->Area_, AreaOverride->Address_);
		}

		AreaOverride->ConditionalBeginDestroy();
	}
}


UPartyHandle* AWorldRemote::GetActivePartyHandle()
{
	return PartyRemote->ActiveParty;
}

void AWorldRemote::LoadZone(FZone* Zone)
{
	AreaManager->LoadZone(Zone);
}