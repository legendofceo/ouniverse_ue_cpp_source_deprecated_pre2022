// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Party.h"
#include "Raid.generated.h"

/**
 * 
 */

USTRUCT()
struct APP_API FRaid
{
	GENERATED_BODY()

public:

	static const int RaidMaxParties;

	FRaid();

	UPROPERTY(VisibleAnywhere)
	FMarshal Marshal;

	UPROPERTY(VisibleAnywhere)
	TArray<FParty> Parties;
};