// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Keyword.generated.h"

/**
 * 
 */

USTRUCT(Blueprintable, BlueprintType)
struct APP_API FKeyword
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FName Keyword;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool bSave;

};