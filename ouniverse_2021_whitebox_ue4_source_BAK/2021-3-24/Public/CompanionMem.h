// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CompanionMem.generated.h"

/**
 * 
 */

USTRUCT(BlueprintType)
struct FCompanionMem
{
	GENERATED_BODY()

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool Obtained = false;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int Level = 0;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int Strength = 0;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int Athleticism = 0;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int Agility = 0;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int Speed = 0;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int Confidence = 0;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int Inteligence = 0;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int Mind = 0;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int Faith = 0;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int Wisdom = 0;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int Charm = 0;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int Beauty = 0;

};