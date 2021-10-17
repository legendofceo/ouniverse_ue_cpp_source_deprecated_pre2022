// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "InputList.h"
#include "Command.generated.h"

/**
 * 
 */


UCLASS(Blueprintable,BlueprintType)
class ONE_API UCommand : public UObject
{
	GENERATED_BODY()

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TEnumAsByte<ECommandID> ID;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool PureModifier;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool Pressed;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float Held;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TEnumAsByte<EControlType> ControlType;
};



UCLASS(Blueprintable, BlueprintType)
class ONE_API UCommandAxis : public UObject
{
	GENERATED_BODY()

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TEnumAsByte<ECommandAxisID> ID;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool PureModifier;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float Power;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TEnumAsByte<EControlType> ControlType;
};
