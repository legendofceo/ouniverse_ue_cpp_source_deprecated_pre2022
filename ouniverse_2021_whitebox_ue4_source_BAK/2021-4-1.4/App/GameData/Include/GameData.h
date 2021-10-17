// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Delegate.h"
#include "Marshal.h"
#include "Log.h"
#include "GameData.generated.h"


UCLASS(Abstract, BlueprintType, Blueprintable)
class APP_API UGameData : public UObject
{
	GENERATED_BODY()
	
public:

	UGameData();

	void Init();

	UFUNCTION()
	void InitSS();

	UPROPERTY()
	FDelegate OnInitComplete;

};