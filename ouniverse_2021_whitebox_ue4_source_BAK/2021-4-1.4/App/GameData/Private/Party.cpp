// Fill out your copyright notice in the Description page of Project Settings.


#include "Party.h"

FParty::FParty()
{
	int MaxParty = 4;

	for (int i = 0; i < MaxParty; i++)
	{
		PartyMembers.Add(FPartyMember());
	}
}

void FPartyMember::SetCompanion(UCompanion* InCompanion)
{
	Companion = InCompanion;
}

void FPartyMember::RemoveCompanion()
{
	Companion = NULL;
}

bool FPartyMember::IsEmpty()
{
	return true;
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
