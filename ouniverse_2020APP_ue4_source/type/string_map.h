// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "string_map.generated.h"



UCLASS(Abstract, Blueprintable)
class UStringMap : public UObject
{
	GENERATED_BODY()

public:


	UStringMap() {};

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<FName, FString> Map;
};