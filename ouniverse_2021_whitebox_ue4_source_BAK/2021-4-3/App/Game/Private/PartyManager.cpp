// Fill out your copyright notice in the Description page of Project Settings.


#include "PartyManager.h"
#include "RaidManager.h"
#include "PartyHandle.h"
#include "Party.h"
#include "Raid.h"
#include "Tally.h"

const int UPartyManager::TID_Buffer = 7812;

void UPartyManager::Init()
{		
	PartyMaxSize = FParty::PartyMaxSize;
	RaidMaxParties = FRaid::RaidMaxParties;

	Party = NewObject<UPartyHandle>(this, UPartyHandle::StaticClass());
	Party->Init(false,0);
	RaidManager = NewObject<URaidManager>(this, URaidManager::StaticClass());
	RaidManager->Init();
}

void UPartyManager::Connect(FParty* PartyData, FRaid* RaidData)
{
	Party->Connect(PartyData);
	RaidManager->Connect(RaidData);
}

void UPartyManager::SetPartyMode(TEnumAsByte<EPartyMode> InPartyMode)
{
	PartyMode = InPartyMode;

	switch (InPartyMode) {
	case EPartyMode::EPartyModeParty:
		ActiveParty = Party;
		break;
	case EPartyMode::EPartyModeRaid:

		break;
	}
}

void UPartyManager::Buffer(FTally* Tally)
{
	Tally->Add(UPartyManager::TID_Buffer);	
	ActiveParty->OnBufferComplete.AddDynamic(this, &UPartyManager::BufferComplete);
	ActiveParty->Buffer();
}

void UPartyManager::BufferComplete()
{
	OnBufferComplete.Broadcast(UPartyManager::TID_Buffer);
}

void UPartyManager::EngagePartyBP()
{

}
