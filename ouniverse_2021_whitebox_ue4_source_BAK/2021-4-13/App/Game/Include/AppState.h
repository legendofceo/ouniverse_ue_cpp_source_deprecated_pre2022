// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "AppState.generated.h"

/**
 * 
 */

class UMythState;
class UPartyState;
class UPartyMemberState;


UCLASS()
class APP_API AAppState : public AGameStateBase
{
	GENERATED_BODY()

	AAppState();

public:


	UFUNCTION(BlueprintCallable, BlueprintPure)
	static AAppState* GetAppState();

	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	UMythState* MythState;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UPartyState* PartyState;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UPartyMemberState* PartyMemberState1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UPartyMemberState* PartyMemberState2;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UPartyMemberState* PartyMemberState3;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UPartyMemberState* PartyMemberState4;

};
