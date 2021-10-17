// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ItemMem.generated.h"

class UItemExEquipHumanLegs;
class UViz;

UCLASS(Abstract, BlueprintType, Blueprintable)
class APP_API UItemMem : public UObject
{
	GENERATED_BODY()

public:

	bool bHasViz = false;

	bool HasViz() { return bHasViz; };
	UFUNCTION(BlueprintImplementableEvent,meta=(DisplayName="#GetViz"))
	TArray<UViz*> GetViz();

};