// Fill out your copyright notice in the Description page of Project Settings.


#include "PartyMember.h"


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
	if (Companion == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}