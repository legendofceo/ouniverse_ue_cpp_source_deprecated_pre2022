// Fill out your copyright notice in the Description page of Project Settings.


#include "MythRemote.h"
#include "AppController.h"
#include "AppMode.h"
#include "MythPro.h"

#include "SpectatorRemote.h"
#include "PartyRemote.h"
#include "CompanionRemote.h"

UMythRemote::UMythRemote()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UMythRemote::Init(AAppController* AP)
{
	URemote::Init(AP);
	SpectatorRemote = AP->SpectatorRemote;
	PartyRemote = AP->PartyRemote;
	CompanionRemote = AP->CompanionRemote;

	MythPro = AAppMode::Get()->MythPro;
	
	SpectatorRemote->Init(AP, MythPro->PartyPro);
	PartyRemote->Init(AP,MythPro->PartyPro);
	CompanionRemote->Init(AP);

}

void UMythRemote::BeginPlay()
{
	Super::BeginPlay();
}

void UMythRemote::Engage()
{
	AAppMode* AppMode = AAppMode::Get();

	if (AppPlayer->IsHost())
	{
		AppPlayer->DebugTextBP("Make HOST automatically possess a party member under certain situations.");

		if(!bInteracted || !AppMode->IsMultiplayer())
		{
			EngageCompanion();
		}
	}
	
	SpectatorRemote->Engage_SERVER();
}

void UMythRemote::EngageCompanion()
{
	PartyEngageStatus = EPartyEngageStatus::Companion;
	AppPlayer->DebugTextBP("Engaging Companion.");
}