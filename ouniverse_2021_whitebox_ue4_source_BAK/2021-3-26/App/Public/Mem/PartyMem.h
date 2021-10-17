// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PartyMemberMem.h"
#include "PartyMem.generated.h"

/**
 * 
 */

USTRUCT(BlueprintType)
struct FPartyMem
{
	GENERATED_BODY()

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TArray<FPartyMemberMem> PartyMembers;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	uint8 Leader;

	FPartyMem()
	{
		PartyMembers.Add(FPartyMemberMem());
		PartyMembers.Add(FPartyMemberMem());
		PartyMembers.Add(FPartyMemberMem());
		PartyMembers.Add(FPartyMemberMem());
		PartyMembers.Add(FPartyMemberMem());
	}
};