// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EquipSlot.generated.h"

/**
 * 
 */

class AActra;
class UBody;
class UEquipable;
enum EEquipSlots;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ONE_API UWearableRack : public UActorComponent
{
	GENERATED_BODY()

public:


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TMap<TEnumAsByte<EEquipSlots>, UEquipSlot*> Map;


};


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ONE_API UEquipSlot : public UActorComponent
{
	GENERATED_BODY()

public:

	
	void Equip(UEquipable* Equipable);

	
	void Setup(UBody* InBody, TEnumAsByte<EEquipSlots> InSlot);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TEnumAsByte<EEquipSlots> Slot;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UEquipable* Equipped;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	UBody* Body;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	AActra* Actra;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool bUndressed;
	
};