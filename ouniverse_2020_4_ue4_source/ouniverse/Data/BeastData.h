// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BeastData.generated.h"


USTRUCT(BlueprintType)
struct OUNIVERSE_API FBeastiaryMD
{
	GENERATED_BODY()

public:

	FBeastiaryMD()
	{

	}

};

UCLASS()
class OUNIVERSE_API UBeastiary : public UObject
{
	GENERATED_BODY()

public:

	UBeastiary();

	static UBeastiary* Create();


	void Load(FBeastiaryMD InMD);
	void LoadQSB();
	void LoadQSC();

	FBeastiaryMD QuickData();
	FString JsonData();

	FBeastiaryMD QSB;
	FBeastiaryMD QSC;

};