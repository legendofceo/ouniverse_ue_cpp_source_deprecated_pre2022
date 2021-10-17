
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CompanionKeys.generated.h"



UCLASS()
class APP_API UCompanionKeys : public UObject
{
	GENERATED_BODY()

public:

	static const int Fione;
	static const int Misha;

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "$Companion Fione"))
	static void FioneKey(int& Key);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "$Companion Misha"))
	static void MishaKey(int& Key);


};