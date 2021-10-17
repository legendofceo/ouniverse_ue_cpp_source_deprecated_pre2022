// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Mng/Mng.h"
#include "ZoneMng.generated.h"



class UZone;

UCLASS(Abstract, BlueprintType, Blueprintable)
class APP_API AZoneMng : public AManagerActor
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	AZoneMng();

public:

	static AZoneMng* Get();

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = ":ZoneMng"))
	static void GetZoneMngBP(AZoneMng*& ZoneMng);

	virtual void BeginPlay() override;
};
