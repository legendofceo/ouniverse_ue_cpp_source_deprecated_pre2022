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

	void Init(bool IsRaid, int InRaidIndex);

	void Connect(FParty* PartyData);

	FParty* PartyData;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool RaidParty;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int RaidIndex;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TArray<UPartyMemberHandle*> PartyMembers;

	void Buffer();

	UFUNCTION()
	void BufferComplete(UTask* Task);

	UPROPERTY(BlueprintAssignable)
	FDelegate OnBufferComplete;
};
