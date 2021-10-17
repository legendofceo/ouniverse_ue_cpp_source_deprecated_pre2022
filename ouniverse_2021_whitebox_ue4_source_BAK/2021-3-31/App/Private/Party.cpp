// Fill out your copyright notice in the Description page of Project Settings.


#include "Party.h"


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
	if (PartyMember1.IsEmpty())
	{
		return &PartyMember1;
	}
	else if (PartyMember2.IsEmpty())
	{
		return &PartyMember2;
	}
	else if (PartyMember3.IsEmpty())
	{
		return &PartyMember3;
	}
	else if (PartyMember4.IsEmpty())
	{
		return &PartyMember4;
	}

	return NULL;
}
