// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Array.h"
#include "UObject/NoExportTypes.h"
#include "Log.generated.h"

#define LOG ULogger::Get()->New()

DECLARE_LOG_CATEGORY_EXTERN(LogApp, Log, All);

class UActorComponent;

UENUM(BlueprintType)
enum class ELogType : uint8
{
	Normal   UMETA(DisplayName = "Normal"),
	Warning  UMETA(DisplayName = "Warning"),
	Critical UMETA(DisplayName = "Critical"),
	Header   UMETA(DisplayName = "Header"),
	Note	 UMETA(DisplayName = "Note"),
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
const ELogType TNOTE = ELogType::Note;
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
	FName System;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FName ID;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FString Text;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	ENetModeII NetMode;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int NetIndex;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool Authority;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	uint8 Indent;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	ELogType LogType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	ELogVerb LogVerbosity;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool DataList = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float Time;

	FLogEntry& W(FString InText);
	FLogEntry& S(FName InSystem);
	FLogEntry& I(FName InID);

	FLogEntry& T(ELogType InLogType);
	FLogEntry& V(ELogVerb InLogVerbosity);

	FLogEntry& N(UActorComponent* InOBJ);

	FLogEntry& DebugM();
	FLogEntry& DebugM(FColor Color, float Duration);

	FString OutputS();
};

UCLASS()
class APP_API ULogger : public UObject
{

	GENERATED_BODY()

public:

	static const float DebugMessageDefaultDuration;
	static const FColor DebugMessageDefaultColor;



	ULogger();


	UFUNCTION(BlueprintCallable,meta=(DisplayName="#Log"))
	static void LogBP(FString InText, FName System, FName ID, ELogType Type, ELogVerb Verbosity);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "#LogPrintScreen"))
	static void LogPrintScreenBP(FString Text, FName System, FName ID, ELogType Type, ELogVerb Verbosity);

	static ULogger* Get();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TArray<FLogEntry> Entries;

	FLogEntry& New();

	FString OutputS();

	void OutputTextFile(FString LogFilePath, FString Signature);

private:

	void OutputTextFile(FString LogFilePath);
};
