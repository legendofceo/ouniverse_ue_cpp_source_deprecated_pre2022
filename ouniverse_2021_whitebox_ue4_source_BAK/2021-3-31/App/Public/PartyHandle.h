// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Party.h"
#include "Type/Array.h"
#include "Delegate.h"
#include "PartyHandle.generated.h"

/**
 * 
 */

class UCompanion;
class UTask;
class UTasks;

UCLASS()
class APP_API UPartyHandle : public UObject
{
	GENERATED_BODY()


public:

	FParty* Party;

	void Load(FParty* InParty);

	UFUNCTION()
	void LoadComplete(UTask* Task);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TSet<UCompanion*> CompanionQue;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	UTasks* LoadPartyTask;

	ArrayC<FPartyMember*> PartyMemberPtrs;

	UPROPERTY(BlueprintAssignable)
	FDelegate OnLoadComplete;
};
