// Fill out your copyright notice in the Description page of Project Settings.


#pragma once

#include "CoreMinimal.h"
#include "Localization.generated.h"


UCLASS(Abstract, Blueprintable)
class OUNIVERSE_API ULocalization : public UObject
{

	GENERATED_BODY()

public:

	void Initialize();

	static ULocalization* Get();
	static ULocalization* Create();

	void PRE();

	TMap<FName, FText> Map;
	FText Decode(FName Key);

	UFUNCTION(BlueprintCallable)
	static FText Decipher(FName Code);

};