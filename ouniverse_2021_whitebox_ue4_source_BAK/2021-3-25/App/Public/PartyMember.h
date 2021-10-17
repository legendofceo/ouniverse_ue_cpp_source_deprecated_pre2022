// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PartyMember.generated.h"

/**
 * 
 */

struct FPartyMemberMem;
class UCompanion;

class APawn;

UCLASS()
class APP_API UPartyMember : public UObject
{
	GENERATED_BODY()

public:

	FPartyMemberMem* Mem;

	void SetMem(FPartyMemberMem* PartyMemberMem);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UCompanion* Companion = NULL;
	
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	int Slot = -1;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	bool Leader = false;

	void SetCompanion(UCompanion* InCompanion);

	void SetLeader(bool BeLeader);

};
