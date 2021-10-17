// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ObjectPlus.h"
#include "Delegate.h"
#include "Pact.h"
#include "PrimaryPro.generated.h"


struct FPact;
class UTroopRemote;


UCLASS(Abstract,BlueprintType, Blueprintable)
class APP_API UPrimaryPro : public UObjectPlus
{
	GENERATED_BODY()

	static const FName SYS;

public:
	// Sets default values for this component's properties
	UPrimaryPro() {};

public:

	static UPrimaryPro* Get();

	UFUNCTION(BlueprintCallable,BlueprintPure,meta=(DisplayName=":PrimaryPro"))
	static void GetBP(UPrimaryPro*& Primary);

	void Engage();
	void Engage_Stream();

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "#EngageBP"))
	void EngageBP();

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	UTroopRemote* TroopRemote = nullptr;

	void ContinueJourney(FPact* Pact);

	void TroopReady();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "#EnterTroopMode"))
	void EnterTroopMode();


};
