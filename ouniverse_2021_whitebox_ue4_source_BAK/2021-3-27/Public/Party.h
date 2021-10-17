// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Marshal/Marshal.h"
#include "Party.generated.h"

/**
 * 
 */

class ACompanion;

USTRUCT()
struct APP_API FPartyMember
{
	GENERATED_BODY()

public:

	UPROPERTY()
	FMarshalNew Marshal;

	UPROPERTY()
	ACompanion* Companion;

	UPROPERTY()
	int Player;
};

USTRUCT()
struct APP_API FParty
{
	GENERATED_BODY()

public:

	UPROPERTY()
	FMarshalNew Marshal;

	UPROPERTY()
	FPartyMember PartyMember1;

	UPROPERTY()
	FPartyMember PartyMember2;

	UPROPERTY()
	FPartyMember PartyMember3;

	UPROPERTY()
	FPartyMember PartyMember4;
};


USTRUCT()
struct APP_API FCompany
{
	GENERATED_BODY()

public:

	UPROPERTY()
	FMarshalNew Marshal;

	UPROPERTY()
	FParty Party1;

	UPROPERTY()
	FParty Party2;

	UPROPERTY()
	FParty Party3;

	UPROPERTY()
	FParty Party4;
};