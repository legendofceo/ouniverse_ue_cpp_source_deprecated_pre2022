// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InventoryData.generated.h"

USTRUCT(BlueprintType)
struct OUNIVERSE_API FItemQD
{
	GENERATED_BODY()

public:

	FItemQD() {};

	bool bMerged;

	int32 BTN;
	int32 Quantity;
	int32 Backpack;
};


USTRUCT(BlueprintType)
struct OUNIVERSE_API FWeaponQD
{
	GENERATED_BODY()

public:

	FWeaponQD() {};

	int32 BTN;
	int32 Backpack;
};

USTRUCT(BlueprintType)
struct OUNIVERSE_API FInventoryQD
{
	GENERATED_BODY()

public:

	FInventoryQD()
	{
		bMerged = false;
	}

	bool bMerged;

	TArray<FItemQD> Items;
	TArray<FWeaponQD> Weapons;

	int32 Rupee;
};


UCLASS()
class OUNIVERSE_API UBackpack : public UObject
{
	GENERATED_BODY()

public:

	UBackpack();

	static UBackpack* Create();
	
};

UCLASS()
class OUNIVERSE_API UInventory : public UObject
{
	GENERATED_BODY()

public:

	UInventory();

	static UInventory* Create();

	TArray<UBackpack> Backpacks;

	void Load(FInventoryQD InMD);
	void LoadQSB();
	void LoadQSC();


	FInventoryQD QuickData();
	FString JsonData();

	FInventoryQD QSB;
	FInventoryQD QSC;

	static enum Backpack {
		None,
		Primary,
		Secondary,
		BACKPACK_MAX,
	};

};