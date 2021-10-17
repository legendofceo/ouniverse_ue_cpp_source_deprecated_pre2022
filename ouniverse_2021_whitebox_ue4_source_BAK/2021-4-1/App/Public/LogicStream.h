// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "LogicStream.generated.h"

/**
 * 
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FLogicStreamDelegate, ULogic*, Logic);

class ULogic;

UCLASS()
class APP_API ULogicStream : public UObject
{
	GENERATED_BODY()

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TSoftClassPtr<ULogic> Class;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	ULogic* Logic;

	void Stream(TSoftClassPtr<ULogic> LogicClass);

	UFUNCTION()
	void StreamLL();

	UFUNCTION()
	void LogicComplete(ULogic* CompletedLogic);

	UPROPERTY(BlueprintAssignable)
	FLogicStreamDelegate OnLogicComplete;

};
