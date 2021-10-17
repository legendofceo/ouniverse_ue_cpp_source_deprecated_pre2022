// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BodyMem.generated.h"


class UVizRack;

UCLASS(BlueprintType, Blueprintable)
class APP_API UBodyMem : public UObject
{
	GENERATED_BODY()

public:

	void Init(UVizRack* InVizRack);

	virtual void BeginInit() {};

	UPROPERTY(VisibleAnywhere)
	UVizRack* VizRack;

};