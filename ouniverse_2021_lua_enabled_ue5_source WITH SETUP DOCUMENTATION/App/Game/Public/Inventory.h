// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Inventory.generated.h"

class UItemMem;


USTRUCT(Blueprintable, BlueprintType)
struct APP_API FInventory
{
	GENERATED_BODY()

public:

	UPROPERTY(VisibleAnywhere)
	TArray<UItemMem*> Items;

	void AddItem(UItemMem* InItem);
};