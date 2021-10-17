// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EquipSlotsEnum.h"
#include "Equipable.generated.h"

/**
 * 
 */

class AActra;
class UBody;
class UBodyHuman;

class AAddon;

UENUM()
enum EEquipableType
{
	EquipTypeNone = 0			UMETA(DisplayName = "None"),
	EquipTypeWearable = 1		UMETA(DisplayName = "Wearable"),
};


UCLASS(Blueprintable)
class ETREIAAPP_API UEquipable : public UObject
{
	GENERATED_BODY()
	
public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	AActra* Actra;

	virtual void Setup(AActra* InActra);

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TEnumAsByte<EEquipSlots> Slot;

	UFUNCTION(BlueprintImplementableEvent)
	void UpdatePoly();

};

UCLASS(Blueprintable)
class ETREIAAPP_API UWearable : public UEquipable
{
	GENERATED_BODY()

public:
	
	//UPROPERTY(EditAnywhere, BlueprintReadOnly)
	//TArray<TEnumAsByte<EBodyType>> AllowedBodyTypes;

	virtual void Setup(AActra* InActra) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UBody* Body;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	USkeletalMeshComponent* Mesh;

	UFUNCTION(BlueprintCallable)
	USkeletalMeshComponent* AttachSkeletonMeshToBody();

};

UCLASS(Blueprintable)
class ETREIAAPP_API UWearableHuman : public UWearable
{
	GENERATED_BODY()

public:

	virtual void Setup(AActra* InActra) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UBodyHuman* BodyHuman;
};

UCLASS(Blueprintable)
class ETREIAAPP_API UWearableNudeBust : public UWearableHuman
{
	GENERATED_BODY()

public:

	virtual TEnumAsByte<EEquipSlots> EquipSlot() { return EEquipSlots::EquipSlotsNudeBust; };

};

UCLASS(Blueprintable)
class ETREIAAPP_API UWearableNudeLegs: public UWearableHuman
{
	GENERATED_BODY()

public:

	virtual TEnumAsByte<EEquipSlots> EquipSlot() { return EEquipSlots::EquipSlotsNudeLegs; };

};

UCLASS(Blueprintable)
class ETREIAAPP_API UWearableNudeHands : public UWearableHuman
{
	GENERATED_BODY()

public:

	virtual TEnumAsByte<EEquipSlots> EquipSlot() { return EEquipSlots::EquipSlotsNudeHands; };

};

UCLASS(Blueprintable)
class ETREIAAPP_API UWearableNudeFeet : public UWearableHuman
{
	GENERATED_BODY()

public:

	virtual TEnumAsByte<EEquipSlots> EquipSlot() { return EEquipSlots::EquipSlotsNudeFeet; };


};