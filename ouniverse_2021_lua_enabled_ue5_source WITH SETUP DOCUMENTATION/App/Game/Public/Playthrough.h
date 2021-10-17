// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Playthrough.generated.h"



UCLASS(Blueprintable, BlueprintType)
class APP_API UPlaythrough : public UObject
{
	GENERATED_BODY()

public:

	UPROPERTY(VisibleAnywhere)
	bool bLocked = false;

	UPROPERTY(VisibleAnywhere)
	int	Difficulty = 1;

	UPROPERTY(VisibleAnywhere)
	int	DifficultyUnlocked = 1;
	
	UPROPERTY(VisibleAnywhere)
	int	PlusUnlocked = 1;

};