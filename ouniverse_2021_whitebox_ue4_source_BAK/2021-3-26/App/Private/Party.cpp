// Fill out your copyright notice in the Description page of Project Settings.


#include "Party.h"
#include "PartyMember.h"
#include "Mem/PartyMem.h"
#include "Companion.h"
#include "CompanionActor.h"

void UParty::Init()
{
	UPartyMember* NewPartyMember;

	int AbsoluteMax = 5;

	for (int i = 0; i < AbsoluteMax; i++)
	{
		NewPartyMember = NewObject<UPartyMember>();
		NewPartyMember->Slot = i;
		PartyMembers.Add(NewPartyMember);
	}
}

void UParty::SetMem(FPartyMem* PartyMem)
{
	Mem = PartyMem;
	int L = PartyMembers.Num();

	for (int i = 0; i < L; i++)
	{
		PartyMembers[i]->SetMem(&Mem->PartyMembers[i]);
	}

}

bool UParty::CanAddMember()
{
	if (MembersNum < MembersMax)
	{
		return true;
	}
	return true;
};

bool UParty::AddPartyMember(UCompanion* Companion)
{

	if (!CanAddMember())
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "Party Full: Member not added. (UParty)");
		return false;
	}

	PartyMembers[MembersNum]->SetCompanion(Companion);
	
	if (MembersNum == 0)
	{
		SetLeader(0);
	}

	MembersNum++;

	return true;
};

void UParty::SetLeader(int MemberNum)
{
	if (Leader != NULL)
	{
		Leader->SetLeader(false);
	}

	Leader = PartyMembers[MemberNum];
	Leader->SetLeader(true);
}

void UParty::Engage()
{
	Leader->Companion->EmbodyActra->BeginEngage();
}