// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "State.h"
#include "PartyMemberState.generated.h"


class UPartyMemberHandle;

UCLASS(BlueprintType, Blueprintable)
class APP_API UPartyMemberState : public UState
{
	GENERATED_BODY()

public:

	UPartyMemberState();

	void Init();

	virtual void BeginPlay() override;

	void Bind(UPartyMemberHandle* InPartyMemberHandle);

	void Unbind();

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	bool bEmpty;

};
