// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BodyMem.h"
#include "Delegate.h"
#include "BodyMemHuman.generated.h"

class UViz;
class UChassis;

class UItemMem;
class UItemMemEquipHumanLegs;
class UItemExEquipHumanLegs;



UCLASS(BlueprintType, Blueprintable)
class APP_API UBodyMemHuman : public UBodyMem
{
	GENERATED_BODY()

	static const FName SYS;

public:


	void BeginInit() override;

	UPROPERTY(EditAnywhere)
	TSoftClassPtr<UChassis> ChassisSoft;

	void StreamChassis(FDelBasic Callback);
	void StreamChassis_Complete(FDelBasic Callback);
	
	UChassis* GetChassis();

	UPROPERTY(EditAnywhere)
	TSubclassOf<UViz> ChestVizBP = nullptr;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UViz> HandsVizBP = nullptr;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UViz> LegsVizBP = nullptr;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UViz> FeetVizBP = nullptr;

};