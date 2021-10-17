// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "LogPP.generated.h"


UENUM(BlueprintType)
enum class LogTypePP : uint8
{
	Normal   UMETA(DisplayName = "Normal"),
	Warning  UMETA(DisplayName = "Warning"),
	Critical UMETA(DisplayName = "Critical"),
	Header   UMETA(DisplayName = "Header"),
	Note	 UMETA(DisplayName = "Note"),
};


UENUM(BlueprintType)
enum class LogVerbPP : uint8
{
	None   UMETA(DisplayName = "None"),
	Light   UMETA(DisplayName = "Light"),
	Medium   UMETA(DisplayName = "Medium"),
	Heavy   UMETA(DisplayName = "Heavy"),
	Massive   UMETA(DisplayName = "Massive"),
	OMFG   UMETA(DisplayName = "OMFG"),
};

USTRUCT(BlueprintType)
struct FLogEntryPP
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
	LogTypePP LogType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	LogVerbPP Verbosity;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool DataList = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float Time;

	FLogEntryPP& W(FString InText);
	FLogEntryPP& S(FName InSystem);
	FLogEntryPP& I(FName InID);

	FLogEntryPP& T(LogTypePP InLogType);

	FLogEntryPP& DebugM();
	FLogEntryPP& DebugM(FColor Color);

	FString OutputS();
};

USTRUCT(BlueprintType,Blueprintable)
struct APPEDITOR_API FLogPP
{

	GENERATED_BODY()

public:


	UPROPERTY(VisibleAnywhere)
	TArray<FLogEntryPP> Entries;

	FLogEntryPP& New();

	FString OutputS();

	void OutputTextFile(FString LogFilePath, FString Signature);

private:

	void OutputTextFile(FString LogFilePath);
};
