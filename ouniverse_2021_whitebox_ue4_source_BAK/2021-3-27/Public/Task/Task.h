// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Task.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTaskDelegate, UTask*, Task);

UCLASS()
class APP_API UTask : public UObject
{
	GENERATED_BODY()

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool Completed = false;

	UFUNCTION()
	virtual void Go();

	UFUNCTION()
	virtual void Complete();

	UPROPERTY()
	FTaskDelegate OnComplete;
};