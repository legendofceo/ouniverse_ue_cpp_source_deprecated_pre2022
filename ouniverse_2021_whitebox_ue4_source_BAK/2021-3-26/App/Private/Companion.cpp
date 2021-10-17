// Fill out your copyright notice in the Description page of Project Settings.


#include "Companion.h"
#include "Mem/CompanionMem.h"
#include "CompanionActor.h"
#include "Party.h"
#include "Story.h"
#include "Engine/StreamableManager.h"
#include "Engine/AssetManager.h"

void UCompanion::SetKey(int CompanionKey)
{
	Key = CompanionKey;
}

void UCompanion::SetMem(FCompanionMem* CompanionMem)
{
	Mem = CompanionMem;
}

void UCompanion::SetStory(UStory* InStory)
{
	Story = InStory;
}

UCompanion* UCompanion::Obtain()
{
	Mem->Obtained = true;
	return this;
}

void UCompanion::ObtainBP(UCompanion*& Companion)
{
	Companion = Obtain();
}


bool UCompanion::IsObtained()
{
	return Mem->Obtained;
}

void UCompanion::IsObtainedBP(EYesNo& Execs)
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

void UCompanion::JoinParty()
{
	Story->Party->AddPartyMember(this);
}

void UCompanion::JoinPartyBP(bool& Success, UCompanion*& CompanionR)
{
	JoinParty();
	CompanionR = this;
}