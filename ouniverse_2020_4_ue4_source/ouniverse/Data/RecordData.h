// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RecordData.generated.h"


USTRUCT(BlueprintType)
struct OUNIVERSE_API FRecordMD
{
	GENERATED_BODY()

public:

	FRecordMD()
	{

	}

	int32 DamageDone;
	int32 FioneDamageDone;

};

UCLASS()
class OUNIVERSE_API URecord : public UObject
{
	GENERATED_BODY()

public:

	URecord();

	static URecord* Create();


	void Load(FRecordMD InMD);
	void LoadQSB();
	void LoadQSC();

	FRecordMD QuickData();
	FString JsonData();

	FRecordMD LiveData;
	FRecordMD QSB;
	FRecordMD QSC;

};