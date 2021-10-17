// Fill out your copyright notice in the Description page of Project Settings.


#include "WorldAnnex.h"
#include "AreaManager.h"
#include "PartyManager.h"

#include "Story.h"
#include "Playthrough.h"

#include "AreaOverride.h"
#include "PartyHandle.h"

#include "Blue.h"

namespace Manager
{
	UWorldAnnex* Story = NULL;
}

UWorldAnnex::UWorldAnnex() : UAnnex(){}

UWorldAnnex* UWorldAnnex::Get()
{
	return Manager::Story;
}

void UWorldAnnex::GetStoryMngBP(UWorldAnnex*& StoryMng)
{
	StoryMng = Manager::Story;
}

void UWorldAnnex::Init()
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
	AreaManager = NewObject<UAreaManager>(this, UAreaManager::StaticClass());
	PartyManager = NewObject<APartyRemote>(this, APartyRemote::StaticClass());
	PartyManager->Init();
	Log.Write(AAUTH,LNORM,VNONE,1,0, "Init()");
	bInit = true;
	OnInitComplete.Broadcast(this);
		
}




void UWorldAnnex::EnterWorld()
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
		PartyManager->Connect(&ActiveStory->Party, &ActiveStory->Raid);
		PartyManager->SetPartyMode(EPartyMode::EPartyModeParty);
		PartyManager->OnBufferComplete.AddDynamic(this,&UWorldAnnex::EnterWorld_Tally);
		PartyManager->Buffer(&Tally);
	}
}


void UWorldAnnex::EnterWorld_Tally(int TID)
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


UPartyHandle* UWorldAnnex::GetActivePartyHandle()
{
	return PartyManager->ActiveParty;
}

void UWorldAnnex::LoadZone(FZone* Zone)
{
	AreaManager->LoadZone(Zone);
}