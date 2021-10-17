// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/DataTable.h"
#include "Item.generated.h"

/**
 * 
 */

class UEquipable;

USTRUCT()
struct ETREIAAPP_API FItemRow : public FTableRowBase
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<UEquipable*> Equipables;

};

UCLASS(Blueprintable)
class ETREIAAPP_API UItem : public UObject
{
	GENERATED_BODY()

public:

	void Setup(FName Key);

};