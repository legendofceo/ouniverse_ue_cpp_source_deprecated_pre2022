// Fill out your copyright notice in the Description page of Project Settings.


#include "RaidManager.h"
#include "PartyHandle.h"
#include "Raid.h"

void URaidManager::Init()
{
	UPartyHandle* PH = NULL;

	for (int i = 0; i < FRaid::RaidMaxParties; i++)
	{
		PH = NewObject<UPartyHandle>(this, UPartyHandle::StaticClass());
		PH->Init(true,i);
		Parties.Add(PH);
	}
}

void URaidManager::Connect(FRaid* InRaidData)
{
	RaidData = InRaidData;
}