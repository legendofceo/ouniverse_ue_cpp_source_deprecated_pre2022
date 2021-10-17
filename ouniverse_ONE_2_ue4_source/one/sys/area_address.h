// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "data_address.h"
#include "area_address.generated.h"

class AArea;

USTRUCT(BlueprintType)
struct FAreaAddress
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	FDataAddress DataAddress_;

	UPROPERTY(EditAnywhere)
	FString Catalyst;

	TArray<FString> Flags;

	UPROPERTY(EditAnywhere)
	FString SpecialExtra;

	FAreaAddress()
	{
		DataAddress_ = FDataAddress(-1, -1);
	}

	FAreaAddress(FDataAddress InDataAddress)
	{
		DataAddress_ = InDataAddress;
	}

	void SetCatalyst(FString InCatalyst)
	{
		Catalyst = InCatalyst;
	}

	void AddFlag(FString InFlag)
	{
		Flags.Add(InFlag);
	}

	FDataAddress DataAddress()
	{
		return DataAddress_;
	}
};