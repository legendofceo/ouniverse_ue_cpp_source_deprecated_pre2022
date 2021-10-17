// Fill out your copyright notice in the Description page of Project Settings.


#include "PartyHandle.h"
#include "PartyMemberHandle.h"
#include "AppInstance.h"
#include "Companion.h"
#include "Party.h"
#include "Task.h"

void UPartyHandle::Init(FParty* InParty)
{
	Party = InParty;

	PartyMaxSize = Party->PartyMembers.Num();

	UPartyMemberHandle* PM = NULL;

	for (int i = 0; i < PartyMaxSize; i++)
	{
		PM = NewObject<UPartyMemberHandle>(this, UPartyMemberHandle::StaticClass());
		PM->Init(&Party->PartyMembers[i]);
		PartyMembers.Add(PM);
	}

}

void UPartyHandle::BufferActra()
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

	TK->OnComplete.AddDynamic(this, &UPartyHandle::LoadComplete);
	TK->Go();
}


void UPartyHandle::LoadComplete(UTask* Task)
{
	OnLoadComplete.Broadcast();
}