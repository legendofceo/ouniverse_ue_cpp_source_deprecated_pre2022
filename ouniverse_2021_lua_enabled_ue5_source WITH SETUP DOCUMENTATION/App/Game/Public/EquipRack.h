// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EquipSlot.h"
#include "EquipRack.generated.h"


class UItemMem;
class UVizRack;



UCLASS(BlueprintType, Blueprintable)
class APP_API UEquipRack : public UObject
{
	GENERATED_BODY()

public:


	void Init(UVizRack* VizRack);

	void EquipItem(UItemMem* ItemToAdd);
	void RemoveItem(UItemMem* ItemToRemove);

	UPROPERTY(VisibleAnywhere)
	UVizRack* VizRack;

	UPROPERTY(VisibleAnywhere)
	TArray<FEquipSlot> EquipmentSlots;


	void AddSlot(int SlotType);
};