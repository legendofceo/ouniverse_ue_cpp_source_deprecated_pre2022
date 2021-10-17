// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Logic.generated.h"

/**
 * 
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FLogicDelegate, ULogic*, Logic);

UCLASS(Abstract, BlueprintType, Blueprintable)
class APP_API ULogic : public UObject
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "@Logic"))
	void DoLogic();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "#Logic Complete"))
	void LogicComplete();

	UPROPERTY(BlueprintAssignable)
	FLogicDelegate OnLogicComplete;

};