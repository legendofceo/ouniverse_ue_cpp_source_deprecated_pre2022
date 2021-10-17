// Fill out your copyright notice in the Description page of Project Settings.


#include "PartyRemote.h"
#include "AppController.h"
#include "AppMode.h"
#include "RaidManager.h"
#include "PartyHandle.h"
#include "Party.h"
#include "Raid.h"
#include "Tally.h"
#include "CompanionRemote.h"

const int APartyRemote::TID_Buffer = 7812;

APartyRemote::APartyRemote() : ARemote()
{
	UPartyPort* PartyPort = NULL;
	for (int i = 0; i < AAppMode::MaxPlayers; i++)
	{
		FString Name = "PartyPort" + FString::FromInt(i);
		PartyPort = CreateDefaultSubobject<UPartyPort>(*Name);
		PartyPorts.Add(PartyPort);
	}
}

void APartyRemote::BeginPlay()
{		
	PartyMaxSize = FParty::PartyMaxSize;
	RaidMaxParties = FRaid::RaidMaxParties;

	if (HasAuthority())
	{
		Party = NewObject<UPartyHandle>(this, UPartyHandle::StaticClass());
		Party->Init(false, 0);
		RaidManager = NewObject<URaidManager>(this, URaidManager::StaticClass());
		RaidManager->Init();

		FVector Location(0.0f, 0.0f, 0.0f);
		FRotator Rotation(0.0f, 0.0f, 0.0f);
		FActorSpawnParameters SpawnInfo;
		SpawnInfo.bNoFail = true;

		for (int i = 0; i < FParty::PartyMaxSize; i++)
		{
			CompanionRemotes.Add(GetWorld()->SpawnActor<ACompanionRemote>(Location, Rotation, SpawnInfo));
		}

	}

	AAppController::GetAppController(this)->ClientBootTaskComplete(ClientBootTasksEnum::ClientBootTasksPartyRemote);
	
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


void APartyRemote::Engage(APlayerPort* InPlayerPort)
{

}