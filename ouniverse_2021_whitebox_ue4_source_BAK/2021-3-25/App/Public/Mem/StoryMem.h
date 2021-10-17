// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PartyMem.h"
#include "StoryMem.generated.h"

/**
 * 
 */

USTRUCT(BlueprintType)
struct FStoryMem
{
	GENERATED_BODY()

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool Obtained = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FName Area;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FPartyMem Party;
};