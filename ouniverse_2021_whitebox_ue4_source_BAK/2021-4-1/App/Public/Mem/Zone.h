// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Marshal/Marshal.h"
#include "Zone.generated.h"


USTRUCT(BlueprintType)
struct FZone
{
	GENERATED_BODY()

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FName ID;

	UPROPERTY(VisibleAnywhere)
	int Key;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FMarshal Marshal;

	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	TSoftObjectPtr<UWorld> Level;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<TSoftObjectPtr<UWorld>> SubLevels;

	void Enter();
	void Exit() {};

	void Load() {};
	void Unload() {};
};