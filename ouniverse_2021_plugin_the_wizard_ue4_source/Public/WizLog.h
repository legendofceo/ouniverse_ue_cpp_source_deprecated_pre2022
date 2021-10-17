// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "WizLog.generated.h"


UENUM(BlueprintType)
enum class WizLogType : uint8
{
	Normal   UMETA(DisplayName = "Normal"),
	Warning  UMETA(DisplayName = "Warning"),
	Critical UMETA(DisplayName = "Critical"),
	Header   UMETA(DisplayName = "Header"),
	Note	 UMETA(DisplayName = "Note"),
};


UENUM(BlueprintType)
enum class WizLogVerb : uint8
{
	None   UMETA(DisplayName = "None"),
	Light   UMETA(DisplayName = "Light"),
	Medium   UMETA(DisplayName = "Medium"),
	Heavy   UMETA(DisplayName = "Heavy"),
	Massive   UMETA(DisplayName = "Massive"),
	OMFG   UMETA(DisplayName = "OMFG"),
};

USTRUCT(BlueprintType)
struct FWizLogEntry
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FName System;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FName ID;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FString Text;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	uint8 Indent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	WizLogType Type;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	WizLogVerb Verbosity;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool DataList = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float Time;

	FWizLogEntry& W(FString InText);
	FWizLogEntry& S(FName InSystem);
	FWizLogEntry& I(FName InID);

	FWizLogEntry& T(WizLogType InWizLogType);

	FWizLogEntry& DebugM();
	FWizLogEntry& DebugM(FColor Color);

	FString OutputS();
};

USTRUCT(BlueprintType,Blueprintable)
struct THEWIZARD_API FWizLog
{

	GENERATED_BODY()

public:


	UPROPERTY(VisibleAnywhere)
	TArray<FWizLogEntry> Entries;

	FWizLogEntry& New();

	FString OutputS();

	void OutputTextFile(FString WizLogFilePath, FString Signature);

private:

	void OutputTextFile(FString WizLogFilePath);
};
