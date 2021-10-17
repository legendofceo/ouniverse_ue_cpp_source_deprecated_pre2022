// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "AppState.generated.h"

/**
 * 
 */

UCLASS()
class APP_API AAppState : public AGameStateBase
{
	GENERATED_BODY()

	AAppState();

public:


	UFUNCTION(BlueprintCallable, BlueprintPure)
	static AAppState* GetAppState();
};
