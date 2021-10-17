// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "ItemBaseTable.generated.h"

class UItemBase;
class UItemOld;

USTRUCT(BlueprintInternalUseOnly)
struct FItemBaseTable : public FTableRowBase
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere)
	TSoftClassPtr<UItemBase> ItemBaseClass;
	

	UPROPERTY(EditAnywhere)
	int NumID;

	UPROPERTY(EditAnywhere)
	FText Description;

};