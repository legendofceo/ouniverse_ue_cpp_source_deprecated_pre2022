// Fill out your copyright notice in the Description page of Project Settings.


#include "PartyMember.h"

void UPartyMember::SetMem(FPartyMemberMem* PartyMemberMem)
{
	Mem = PartyMemberMem;
}

void UPartyMember::SetCompanion(UCompanion* InCompanion)
{
	Companion = InCompanion;
}

void UPartyMember::SetLeader(bool BeLeader)
{
	if (BeLeader)
	{
		Leader = true;
	}
	else
	{
		Leader = false;
	}
}