// Fill out your copyright notice in the Description page of Project Settings.


#include "PartyHandle.h"
#include "PartyMemberHandle.h"
#include "AppInstance.h"
#include "Companion.h"
#include "Party.h"
#include "Task.h"

void UPartyHandle::Init(bool IsRaid, int InRaidIndex)
{
	RaidParty = IsRaid;
	RaidIndex = InRaidIndex;

	UPartyMemberHandle* PM = NULL;

	for (int i = 0; i < FParty::PartyMaxSize; i++)
	{
		PM = NewObject<UPartyMemberHandle>(this, UPartyMemberHandle::StaticClass());
		PartyMembers.Add(PM);
	}
}

void UPartyHandle::Connect(FParty* InPartyData)
{
	PartyData = InPartyData;

	for (int i = 0; i < FParty::PartyMaxSize; i++)
	{
		PartyMembers[i]->Connect(&PartyData->PartyMembers[i]);
	}

}

void UPartyHandle::Buffer()
{
	UTasks* TK = UTasks::New(this);
	UApp::Get()->RegLocalTask(TK);

	for (UPartyMemberHandle* PM : PartyMembers)
	{
		if (PM->HasCompanion())
		{
			TK->Add(PM->BeCompanionA());
		}
	}

	TK->OnComplete.AddDynamic(this, &UPartyHandle::BufferComplete);
	TK->Go();
}


void UPartyHandle::BufferComplete(UTask* Task)
{
	OnBufferComplete.Broadcast();
}

UPartyMemberHandle* UPartyHandle::GetHighestPriorityAvailableMember()
{
	return PartyMembers[0];
}