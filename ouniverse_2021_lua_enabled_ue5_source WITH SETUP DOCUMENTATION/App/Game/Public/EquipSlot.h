// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EquipSlot.generated.h"


class UItemMem;

USTRUCT(Blueprintable, BlueprintType)
struct APP_API FEquipSlot
{
	GENERATED_BODY()

public:

	FEquipSlot() {};

	FEquipSlot(int InSlotType)
	{
		SlotType = InSlotType;
	}

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int SlotType = 0;

	UPROPERTY(VisibleAnywhere)
	UItemMem* Worn = nullptr;

	UPROPERTY(VisibleAnywhere)
	UItemMem* Transmog = nullptr;

	UPROPERTY(VisibleAnywhere)
	UItemMem* FullTMog = nullptr;

};
