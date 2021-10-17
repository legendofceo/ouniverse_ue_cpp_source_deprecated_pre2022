// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Delegate.h"
#include "PartyHandle.generated.h"

/**
 * 
 */

struct FParty;
class UPartyMemberHandle;
class UCompanion;
class UTasks;

UCLASS()
class APP_API UPartyHandle : public UObject
{
	GENERATED_BODY()


public:

	FParty* Party;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int PartyMaxSize;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TArray<UPartyMemberHandle*> PartyMembers;

	void Init(FParty* InParty);

	void BufferActra();

	UFUNCTION()
	void LoadComplete(UTask* Task);

	UPROPERTY(BlueprintAssignable)
	FDelegate OnLoadComplete;
};
