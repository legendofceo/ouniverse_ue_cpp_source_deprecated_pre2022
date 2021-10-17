// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Item.generated.h"

/**
 * 
 */

class UAddon;


USTRUCT(Blueprintable, BlueprintType)
struct APP_API FFitting
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<FName> RequiredKeywords;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<int> Slots;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UAddon* Addon;

};

UCLASS(Blueprintable, BlueprintType)
class APP_API UItem : public UObject
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int Type = 0;


	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int Consumable = 0;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int Wearable = 0;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<FFitting> Fittings;


};


UCLASS(Blueprintable, BlueprintType)
class APP_API UEquip : public UItem
{
	GENERATED_BODY()

public:



};