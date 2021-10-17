// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Marshal.h"
#include "PartyMember.generated.h"

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