// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "State.h"
#include "PartyState.generated.h"



class UPartyMemberState;
class UPartyHandle;

UCLASS(BlueprintType, Blueprintable)
class APP_API UPartyState : public UState
{
	GENERATED_BODY()

public:

	UPartyState();

	static UPartyState* Get();

	void Init();

	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	TArray<UPartyMemberState*> PartyMemberStates;


	void NewActiveParty(UPartyHandle* PartyHandle);

};
