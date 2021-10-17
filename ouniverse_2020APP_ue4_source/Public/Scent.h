// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Components/SphereComponent.h"
#include "Scent.generated.h"

/**
 * 
 */

UENUM()
enum EScent
{
	ScentFloral				UMETA(DisplayName = "Female01"),
	ScentCreature			UMETA(DisplayName = "Female02"),
	ScentEthnicity			UMETA(DisplayName = "Male01"),
	ScentCulturalCuisine	UMETA(DisplayName = "Male01"),
};

UENUM()
enum EEthnicity
{
	EthnicityIbalyss		UMETA(DisplayName = "Female01"),
	EthnicityCole		UMETA(DisplayName = "Female02"),
	EthnicityRaxx			UMETA(DisplayName = "Male01"),
};

UENUM()
enum ERace
{
	RaceHuman		UMETA(DisplayName = "Female01"),
	RaceElf		UMETA(DisplayName = "Female02"),
	RaceGnome			UMETA(DisplayName = "Male01"),
};

UENUM()
enum EBeast
{
	BeastHawk		UMETA(DisplayName = "Female01"),
	BeastBear		UMETA(DisplayName = "Female02"),
	BeastCow			UMETA(DisplayName = "Male01"),
};

UCLASS()
class ETREIAAPP_API USmell : public UObject
{
	GENERATED_BODY()
	
};


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ETREIAAPP_API USmellRadius : public USphereComponent
{
	GENERATED_BODY()
};

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ETREIAAPP_API USenseSmell : public USphereComponent
{
	GENERATED_BODY()
};