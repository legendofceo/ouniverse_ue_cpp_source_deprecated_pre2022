// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Slot.generated.h"

/**
 * 
 */


USTRUCT(Blueprintable, BlueprintType)
struct APP_API FSlot
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		TArray<int> Slots;

};