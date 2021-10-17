// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "path_address.generated.h"


USTRUCT(BlueprintType)
struct FPathAddress
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	int PackUN;

	UPROPERTY(EditAnywhere)
	FString Path;

	FPathAddress()
	{
		PackUN = -1;
		Path = "";
	}

	FPathAddress(int Pack, FString InPath)
	{
		PackUN = Pack;
		Path = InPath;
	}
};