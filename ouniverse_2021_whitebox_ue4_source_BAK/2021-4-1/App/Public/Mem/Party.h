// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Marshal/Marshal.h"
#include "Party.generated.h"

/**
 * 
 */

class UCompanion;

USTRUCT()
struct APP_API FPartyMember
{
	GENERATED_BODY()

public:

	UPROPERTY(VisibleAnywhere)
	FMarshal Marshal;

	UPROPERTY(VisibleAnywhere)
	UCompanion* Companion = NULL;

	UPROPERTY(VisibleAnywhere)
	int Player;

	void SetCompanion(UCompanion* InCompanion);
	void RemoveCompanion();
	bool IsEmpty();
};

USTRUCT()
struct APP_API FParty
{
	GENERATED_BODY()

public:

	UPROPERTY(VisibleAnywhere)
	FMarshal Marshal;

	UPROPERTY(VisibleAnywhere)
	TArray<FPartyMember> PartyMembers;

	void AddCompanion(UCompanion* Companion);

	FPartyMember* GetFirstFreeCompanionSlot();
};


USTRUCT()
struct APP_API FCompany
{
	GENERATED_BODY()

public:

	UPROPERTY(VisibleAnywhere)
	FMarshal Marshal;

	UPROPERTY(VisibleAnywhere)
	FParty Party1;

	UPROPERTY(VisibleAnywhere)
	FParty Party2;

	UPROPERTY(VisibleAnywhere)
	FParty Party3;

	UPROPERTY(VisibleAnywhere)
	FParty Party4;
};