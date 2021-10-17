// Fill out your copyright notice in the Description page of Project Settings.


#include "PartyManager.h"
#include "RaidManager.h"
#include "PartyHandle.h"
#include "Party.h"
#include "Raid.h"
#include "Tally.h"

const int APartyRemote::TID_Buffer = 7812;

void APartyRemote::Init()
{		
	PartyMaxSize = FParty::PartyMaxSize;
	RaidMaxParties = FRaid::RaidMaxParties;

	Party = NewObject<UPartyHandle>(this, UPartyHandle::StaticClass());
	Party->Init(false,0);
	RaidManager = NewObject<URaidManager>(this, URaidManager::StaticClass());
	RaidManager->Init();
}

void APartyRemote::Connect(FParty* PartyData, FRaid* RaidData)
{
	Party->Connect(PartyData);
	RaidManager->Connect(RaidData);
}

void APartyRemote::SetPartyMode(TEnumAsByte<EPartyMode> InPartyMode)
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

void APartyRemote::Buffer(FTally* Tally)
{
	Tally->Add(APartyRemote::TID_Buffer);	
	ActiveParty->OnBufferComplete.AddDynamic(this, &APartyRemote::BufferComplete);
	ActiveParty->Buffer();
}

void APartyRemote::BufferComplete()
{
	OnBufferComplete.Broadcast(APartyRemote::TID_Buffer);
}

void APartyRemote::EngagePartyBP()
{

}
