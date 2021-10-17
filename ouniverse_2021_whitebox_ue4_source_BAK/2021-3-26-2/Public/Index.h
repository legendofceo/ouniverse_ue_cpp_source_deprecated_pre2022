// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Index.generated.h"

/**
 * 
 */

UCLASS()
class APP_API UIndexByte : public UObject
{
	GENERATED_BODY()

public:

	static UIndexByte* CreateIndexByte(uint8 MinValue, uint8 MaxValue, uint8 StartValue);

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	uint8 Value;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	uint8 Min;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	uint8 Max;

	UFUNCTION(Category=IndexByte, BlueprintCallable)
	uint8 IncrementValue(bool bReverse);

	UFUNCTION(Category=IndexByte,BlueprintCallable)
	uint8 SetValue(uint8 NewValue);

};