// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "State.h"
#include "MythState.generated.h"


UCLASS(BlueprintType, Blueprintable)
class APP_API UMythState : public UState
{
	GENERATED_BODY()

public:

	UMythState();

	virtual void BeginPlay() override;
};
