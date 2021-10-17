// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Delegate.h"
#include "Hair.generated.h"


class UViz;
class UVizRack;
class UChassis;

UCLASS(Abstract, BlueprintType, Blueprintable)
class APP_API UHair : public UObject
{
	GENERATED_BODY()

public:

	void Init(UVizRack* InVizRack);

	virtual void BeginInit() {};

	UPROPERTY(VisibleAnywhere)
		UVizRack* VizRack;

};


UCLASS(Abstract, BlueprintType, Blueprintable)
class APP_API UHairHuman : public UHair
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
		TSubclassOf<UViz> HairVizBP = nullptr;

};