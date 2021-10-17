// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "AGI.generated.h"

/**
 * 
 */

UCLASS()
class ONE_API UGI : public UGameInstance
{
	GENERATED_BODY()

public:

	UGI();
	static UGI* Get();

	virtual void Init();

	UFUNCTION(BlueprintCallable,BlueprintPure)
	static UGI* GetGlobal();


};