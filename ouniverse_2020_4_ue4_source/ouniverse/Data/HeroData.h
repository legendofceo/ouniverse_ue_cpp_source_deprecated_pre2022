// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HeroData.generated.h"


USTRUCT(BlueprintType)
struct OUNIVERSE_API FHeroMD
{
	GENERATED_BODY()

public:

	FHeroMD()
	{

	}

};

USTRUCT(BlueprintType)
struct OUNIVERSE_API FTroupeMD
{
	GENERATED_BODY()

public:

	FTroupeMD()
	{

	}

};

UCLASS()
class OUNIVERSE_API UHeroPD : public UObject
{
	GENERATED_BODY()

public:

	UHeroPD();

	static UHeroPD* Create();
};

UCLASS()
class OUNIVERSE_API UTroupe : public UObject
{
	GENERATED_BODY()

public:

	UTroupe();

	static UTroupe* Create();

	TArray<UHeroPD> Heroes;

	void Load(FTroupeMD InMD);
	void LoadQSB();
	void LoadQSC();

	FTroupeMD QuickData();
	FString JsonData();

	FTroupeMD QSB;
	FTroupeMD QSC;
	
	static enum Hero {
		None,
		Fione,
		Lexis,
		Pasq,
		HERO_MAX,
	};

};