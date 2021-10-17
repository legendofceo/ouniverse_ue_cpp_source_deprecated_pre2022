// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

class UHero;

class OUNIVERSE_API PartyC 
{

public:

	PartyC();

	static PartyC* Get();
	static PartyC* Create();

	TArray<UHero*> PartyMembers;

	TArray<UHero*> ActiveMembers;

	void SetActiveMember(int MemberSlot, UHero* NewActiveMember);

	void SpawnParty();
	void DespawnParty();
};