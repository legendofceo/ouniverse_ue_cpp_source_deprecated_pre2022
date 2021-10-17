// Fill out your copyright notice in the Description page of Project Settings.


#include "OnwardRemote.h"
#include "LOG.h"
#include "AppController.h"
#include "AppMode.h"
#include "PartyManager.h"
#include "PartyHandle.h"
#include "MythPro.h"

#include "SpectatorRemote.h"
#include "PartyRemote.h"
#include "CompanionRemote.h"

const FName UOnwardRemote::SYS = "OnwardRemote";

UOnwardRemote::UOnwardRemote() :URemote()
{
}

void UOnwardRemote::Init(AAppController* AP, UMythPro* InMythPro)
{
	URemote::Init(AP);
	SpectatorRemote = AP->SpectatorRemote;
	PartyRemote = AP->PartyRemote;
	CompanionRemote = AP->CompanionRemote;

	MythPro = InMythPro;
	
	SpectatorRemote->Init(AP, MythPro->PartyPro);
	PartyRemote->Init(AP,MythPro->PartyPro);
	CompanionRemote->Init(AP);

}

void UOnwardRemote::BeginPlay()
{
	Super::BeginPlay();
}

void UOnwardRemote::Engage()
{
	AAppMode* AppMode = AAppMode::Get();

	if (AppPlayer->IsHost())
	{
		LOG.S(SYS).T(TNOTE).N(this).W("NOTE: Make HOST automatically possess a party member under certain situations.");

		if(!bInteracted || !AppMode->IsMultiplayer())
		{
			UPartyHandle* PartyHandle = MythPro->GetActivePartyHandle();
			UPartyMemberHandle* PartyMemberHandle = PartyHandle->GetHighestPriorityAvailableMember();
			EngageCompanion(PartyMemberHandle);
		}
	}
	else
	{
		SpectatorRemote->Engage_SERVER();
	}
}

void UOnwardRemote::EngageCompanion(UPartyMemberHandle* PartyMemberHandle)
{
	LOG.S(SYS).N(this).W("Engaging Companion");
	PartyEngageStatus = EPartyEngageStatus::Companion;
	CompanionRemote->Engage(PartyMemberHandle);
	
}