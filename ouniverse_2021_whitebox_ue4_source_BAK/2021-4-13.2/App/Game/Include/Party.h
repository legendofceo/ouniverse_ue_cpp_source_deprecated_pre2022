// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PartyMember.h"
#include "Party.generated.h"

/**
 * 
 */

class UCompanion;


USTRUCT()
struct APP_API FParty
{
	GENERATED_BODY()

public:

	static const int PartyMaxSize;

	FParty();

	UPROPERTY(VisibleAnywhere)
	FMarshal Marshal;

	UPROPERTY(VisibleAnywhere)
	TArray<FPartyMember> PartyMembers;

	void AddCompanion(UCompanion* Companion);

	FPartyMember* GetFirstFreeCompanionSlot();
};