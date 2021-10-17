// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Party.h"
#include "Company.generated.h"

/**
 * 
 */

USTRUCT()
struct APP_API FCompany
{
	GENERATED_BODY()

public:

	UPROPERTY(VisibleAnywhere)
	FMarshal Marshal;

	UPROPERTY(VisibleAnywhere)
	FParty Party1;

	UPROPERTY(VisibleAnywhere)
	FParty Party2;

	UPROPERTY(VisibleAnywhere)
	FParty Party3;

	UPROPERTY(VisibleAnywhere)
	FParty Party4;
};