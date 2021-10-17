// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BodyTypes.generated.h"


UENUM(BlueprintType)
enum class BodyTypes : uint8
{
	None	  UMETA(DisplayName = "None"),
	Human  UMETA(DisplayName = "Human"),
	Creature  UMETA(DisplayName = "Creature"),
};

UENUM(BlueprintType)
enum class BodyTypesHuman : uint8
{
	None			UMETA(DisplayName = "None"),
	FemaleAverage	UMETA(DisplayName = "FemaleAverage"),
	FemaleBusty		UMETA(DisplayName = "FemaleBusty"),
};

UENUM(BlueprintType)
enum class BodyTypesCreature : uint8
{
	None	  UMETA(DisplayName = "None"),
	Head	  UMETA(DisplayName = "Head"),
	Chest	  UMETA(DisplayName = "Chest"),
	Legs	  UMETA(DisplayName = "Legs"),
	Hands	  UMETA(DisplayName = "Hands"),
	Feet	  UMETA(DisplayName = "Feet"),
};

USTRUCT(Blueprintable, BlueprintType)
struct APP_API FBodyType
{
	GENERATED_BODY()

public:

	static const int SBody;
	static const int SHead;

	static const int CHead;
	static const int CChest;
	static const int CLegs;
	static const int CHands;
	static const int CFeet;


	UPROPERTY(EditAnywhere)
	BodyTypes Type;

	UPROPERTY(EditAnywhere)
	BodyTypesHuman Human;

	UPROPERTY(EditAnywhere)
	BodyTypesCreature Creature;

	FBodyType()
	{
		Type = BodyTypes::None;
		Human = BodyTypesHuman::None;
		Creature = BodyTypesCreature::None;
	}

	FBodyType(BodyTypesHuman Enum)
	{
		Type = BodyTypes::None;
		Human = Enum;
		Creature = BodyTypesCreature::None;
	}

	FBodyType(BodyTypesCreature Enum)
	{
		Type = BodyTypes::None;
		Human = BodyTypesHuman::None;
		Creature = Enum;
	}

	int Get();

private:

	int GetHuman();
	int GetCreature();
};