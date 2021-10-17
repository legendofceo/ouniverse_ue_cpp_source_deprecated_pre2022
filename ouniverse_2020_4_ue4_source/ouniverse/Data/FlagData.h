// Fill out your copyright notice in the Description page of Project Flags.

#pragma once

#include "CoreMinimal.h"
#include "FlagData.generated.h"


USTRUCT(BlueprintType)
struct OUNIVERSE_API FFlagsMD
{
	GENERATED_BODY()

public:

	FFlagsMD()
	{

	}

	int32 MinutesPlayer;
	int32 Book1Clear;
	int32 Book2Clear;

	int32 Chapter1Clear;
	int32 Chapter2Clear;
	int32 Chapter3Clear;


	int32 Chapter1DifficultyClear;
	int32 Chapter2DifficultyClear;
	int32 Chapter3DifficultyClear;
	int32 Chapter4DifficultyClear;
	int32 Chapter5DifficultyClear;
};

UCLASS()
class OUNIVERSE_API UFlags : public UObject
{
	GENERATED_BODY()

public:

	UFlags();

	static UFlags* Create();


	void Load(FFlagsMD InMD);
	void LoadQSB();
	void LoadQSC();

	FFlagsMD QuickData();
	FString JsonData();

	FFlagsMD QSB;
	FFlagsMD QSC;

};