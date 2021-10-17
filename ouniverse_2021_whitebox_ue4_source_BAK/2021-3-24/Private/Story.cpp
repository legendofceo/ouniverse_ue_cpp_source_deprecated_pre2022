// Fill out your copyright notice in the Description page of Project Settings.


#include "Story.h"
#include "Companion.h"
#include "Party.h"
#include "StoryMem.h"


void UStory::SetKey(int NewKey)
{
	Key = NewKey;
}

void UStory::Init()
{
	InitBP();
	Initialized = true;
}

UCompanion* UStory::AddCompanion(UCompanion* Companion)
{
	Companions.Add(Companion->Key, Companion);
	return Companion;
}

UCompanion* UStory::GetCompanion(int CompanionKey)
{
	return Companions.FindRef(CompanionKey);
}

void UStory::SetMem(FStoryMem* StoryMem)
{
	Mem = StoryMem;
	Party->SetMem(&StoryMem->Party);
}

UStory* UStory::Obtain()
{
	Mem->Obtained = true;
	DoObtained();
	return this;
}

void UStory::ObtainBP(UStory*& Story)
{
	Story = Obtain();
}

bool UStory::IsObtained()
{
	return Mem->Obtained;
}

void UStory::IsObtainedBP(EYesNo& Execs)
{
	if (Mem->Obtained)
	{
		Execs = EYesNo::Yes;
	}
	else
	{
		Execs = EYesNo::No;
	}
}



UParty* UStory::GetParty()
{
	return Party;
}

void UStory::GetPartyBP(UParty*& OutParty)
{
	OutParty = Party;
}

void UStory::SetAreaAddressOverride(FAreaAddress AreaAddress)
{
	AreaAddressOverride = AreaAddress;
}

bool UStory::HasAreaAddressOverride()
{
	if (AreaAddressOverride.IsValid())
	{
		return true;
	}
	else
	{
		return false;
	}
}

FAreaAddress UStory::GetAreaAddressOverride()
{
	return AreaAddressOverride;
}

void UStory::ClearAreaAddressOverride()
{
	AreaAddressOverride.Invalidate();
}