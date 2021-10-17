// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "AppInstance.generated.h"

/**
 * 
 */
UCLASS()
class APP_API UAppInstance : public UGameInstance
{
	GENERATED_BODY()


public:
		
	virtual void Init();

	UFUNCTION(BlueprintCallable)
	static UAppInstance* GetAppInstance();
};
