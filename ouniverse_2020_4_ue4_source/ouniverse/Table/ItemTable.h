// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "ItemTable.generated.h"


USTRUCT(BlueprintType)
struct FSchemaItem : public FTableRowBase
{
    GENERATED_USTRUCT_BODY()

public:

    FSchemaItem() {}

    /** The 'Name' column is the same as the XP Level */

    /** XP to get to the given level from the previous level */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = LevelUp)
    FText Name;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = LevelUp)
    FText Description;

};