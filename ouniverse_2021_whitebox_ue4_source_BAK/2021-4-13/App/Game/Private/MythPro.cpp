// Fill out your copyright notice in the Description page of Project Settings.


#include "MythPro.h"

#include "PartyPro.h"
#include "AreaManager.h"
#include "PartyManager.h"
#include "SoftServe.h"

#include "Story.h"
#include "Playthrough.h"

#include "AreaOverride.h"
#include "PartyHandle.h"

#include "Blue.h"


namespace Pro
{
	UMythPro* Myth = NULL;
}

UMythPro::UMythPro() : UProtocol()
{

}

UMythPro* UMythPro::Get()
{
	return Pro::Myth;
}


void UMythPro::Init()
{
	Pro::Myth = this;

#if UE_BUILD_DEVELOPMENT
	/**
	FBlueEnsureImplementation BEF = FBlueEnsureImplementation();
	BEF.Add("InitBP");
	BEF.Add("PreStartBP");
	BEF.Add("PostStartBP");
	BEF.Go(this, ID.ToString());
	*/
#endif

	SS = NewObject<USoftServe>(this, USoftServe::StaticClass());
	
	if (SS->HasNull())
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "A Manager SoftClass is not correctly set in MythPro");
		Log.Write(AAUTH, LCRIT, VNONE, 1, 0, "A Manager SoftClass was not correctly set.");
		return;
	}

	SS->OnComplete.AddDynamic(this, &UMythPro::Init_SS);
	SS->Stream();

}


void UMythPro::Init_SS(USoftServe* SoftServe)
{
	PartyPro = NewObject<UPartyPro>(this, UPartyPro::StaticClass());
	PartyPro->Init();

	AreaManager = NewObject<UAreaManager>(this, UAreaManager::StaticClass());
	AreaManager->Init();

	PartyManager = NewObject<UPartyManager>(this, UPartyManager::StaticClass());
	PartyManager->Init();

	InitComplete();
}

void UMythPro::Engage()
{
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
		PartyManager->OnBufferComplete.AddDynamic(this,&UMythPro::EnterWorld_Tally);
		PartyManager->Buffer(&Tally);
	}
}


void UMythPro::EnterWorld_Tally(int TID)
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


UPartyHandle* UMythPro::GetActivePartyHandle()
{
	return PartyManager->ActiveParty;
}

void UMythPro::LoadZone(FZone* Zone)
{
	AreaManager->LoadZone(Zone);
}