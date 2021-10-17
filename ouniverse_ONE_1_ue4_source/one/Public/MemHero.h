// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/DataTable.h"
#include "MemHero.generated.h"

/**
 *
 */

USTRUCT()
struct ONE_API FMemHeroRow : public FTableRowBase
{
	GENERATED_BODY()

public:

	UPROPERTY(category = Actra, EditAnywhere, BlueprintReadOnly)
		FText FirstName;

	UPROPERTY(category = Actra, EditAnywhere, BlueprintReadOnly)
		FText LastName;
};

UCLASS()
class ONE_API UMemHero : public UObject
{
	GENERATED_BODY()

public:



};