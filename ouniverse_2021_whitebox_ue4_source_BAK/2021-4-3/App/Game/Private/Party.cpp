// Fill out your copyright notice in the Description page of Project Settings.


#include "Party.h"

const int FParty::PartyMaxSize = 4;


FParty::FParty()
{
	for (int i = 0; i < FParty::PartyMaxSize; i++)
	{
		PartyMembers.Add(FPartyMember());
	}
}

void FParty::AddCompanion(UCompanion* Companion)
{
	FPartyMember* OpenSlot = GetFirstFreeCompanionSlot();
	OpenSlot->SetCompanion(Companion);
}

FPartyMember* FParty::GetFirstFreeCompanionSlot()
{
	for (FPartyMember& PM : PartyMembers)
	{
		PM.IsEmpty();
		return &PM;
	}

	return NULL;
}
