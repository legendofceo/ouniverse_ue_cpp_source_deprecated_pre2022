// Fill out your copyright notice in the Description page of Project Settings.


#pragma once

#include "CoreMinimal.h"
#include "Misc/DateTime.h"
#include "log.generated.h"

UENUM()
enum ELogStatus
{
	None			UMETA(DisplayName = "None"),
	Expected		UMETA(DisplayName = "Expected"),
	Notice			UMETA(DisplayName = "Notice"),
	Warning			UMETA(DisplayName = "Warning"),
	Critical		UMETA(DisplayName = "Critical"),
	RequiredData    UMETA(DisplayName = "Required Data"),

};


USTRUCT(BlueprintType)
struct FLogEntry
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere)
	FString Text;

	UPROPERTY(VisibleAnywhere)
	FDateTime TimeStamp;

	UPROPERTY(VisibleAnywhere)
	TEnumAsByte<ELogStatus> Status;

public:

	FLogEntry()
	{
		Text = "";
		TimeStamp = FDateTime();
		Status = ELogStatus::None;
	}
	FLogEntry(FString InText, TEnumAsByte<ELogStatus> InStatus)
	{
		Text = InText;
		Status = InStatus;
		TimeStamp = FDateTime();
	}
};

USTRUCT(BlueprintType)
struct FLogger
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere)
	FString ID;

	UPROPERTY(VisibleAnywhere)
	int Limit = 100;

	UPROPERTY(VisibleAnywhere)
	TArray<FLogEntry> Entries;

public:

	FLogger()
	{
		ID = "";
	}

	FLogger(FString InID)
	{
		ID = InID;
	}

	void Write(FString Text, TEnumAsByte<ELogStatus> Status);

};