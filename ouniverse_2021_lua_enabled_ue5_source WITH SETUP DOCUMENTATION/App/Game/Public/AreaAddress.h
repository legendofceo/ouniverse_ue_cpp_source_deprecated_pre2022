// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AreaAddress.generated.h"

class UArea;


USTRUCT(BlueprintType)
struct FAreaAddressNew
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere)
	FName Area;

	UPROPERTY(EditAnywhere)
	FName Destination;

	UPROPERTY(EditAnywhere)
	FName Catalyst;

	FAreaAddressNew() {};

	FAreaAddressNew(FName InArea, FName InDestination, FName InCatalyst)
	{
		Area = InArea;
		Destination = InDestination;
		Catalyst = InCatalyst;
	}

};