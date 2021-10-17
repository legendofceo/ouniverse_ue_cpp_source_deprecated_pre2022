// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Array.h"
#include "Log.generated.h"

UENUM(BlueprintType)
enum class ELogType : uint8
{
	Normal   UMETA(DisplayName = "Normal"),
	Warning  UMETA(DisplayName = "Warning"),
	Critical UMETA(DisplayName = "Critical"),
	Header   UMETA(DisplayName = "Header"),
};


UENUM(BlueprintType)
enum class ELogVerb : uint8
{
	None   UMETA(DisplayName = "None"),
	Light   UMETA(DisplayName = "Light"),
	Medium   UMETA(DisplayName = "Medium"),
	Heavy   UMETA(DisplayName = "Heavy"),
	Massive   UMETA(DisplayName = "Massive"),
	OMFG   UMETA(DisplayName = "OMFG"),
};

UENUM(BlueprintType)
enum class ENetModeII : uint8
{
	None			UMETA(DisplayName = "None"),
	Standalone UMETA(DisplayName = "Standalone"),
	Dedicated UMETA(DisplayName = "Dedicated"),
	Listen UMETA(DisplayName = "Listen"),
	Client UMETA(DisplayName = "Client"),
};

const ELogType TNORM = ELogType::Normal;
const ELogType TWARN = ELogType::Warning;
const ELogType TCRIT = ELogType::Critical;
const ELogType THEAD = ELogType::Header;

const ELogVerb VNONE = ELogVerb::None;
const ELogVerb VLIGHT = ELogVerb::Light;
const ELogVerb VMED = ELogVerb::Medium;
const ELogVerb VHEAVY = ELogVerb::Heavy;
const ELogVerb VMASSIVE = ELogVerb::Massive;
const ELogVerb VOMFG = ELogVerb::OMFG;


USTRUCT(BlueprintType)
struct FLogEntry
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FString Text;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	ENetModeII NetMode;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int Index;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool Authority;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	uint8 Indent;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	ELogType LogType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	ELogVerb Verbosity;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool DataList = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float Time;

	FLogEntry& Type(ELogType InLogType);
	FLogEntry& UE();
	FLogEntry& DM();

};


USTRUCT(BlueprintType)
struct FLogger
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FName ID;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		FName ID;
	void SetID(FName InID);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TArray<FLogEntry> Entries;

	FLogEntry& W(FString Text);

};


USTRUCT(BlueprintType)
struct FLoggerMaster
{
	GENERATED_BODY()

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int EntryCount = 0;

	ArrayC<FLogEntry*> Entries;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TArray<FLogEntry> EntriesCopy;

	void Add(FLogEntry* LogEntry);

	static void SetMasterLogger(FLoggerMaster* LoggerMaster);

	FString Print();
};
