// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Mng/Mng.h"
#include "AreaAddress.h"
#include "PartyMng.generated.h"

UCLASS(Abstract, BlueprintType, Blueprintable)
class APP_API APartyMng : public AManagerActor
{
	GENERATED_BODY()


public:

	APartyMng();

	static APartyMng* Get();

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = ":PartyMng"))
	static void GetPartyMngBP(APartyMng*& PartyMng);

	virtual void BeginPlay() override;

};
