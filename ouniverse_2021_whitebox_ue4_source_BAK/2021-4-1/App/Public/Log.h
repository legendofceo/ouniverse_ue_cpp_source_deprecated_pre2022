// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Log.generated.h"


UENUM(BlueprintType)
enum ELogStatus
{
	ELogStatusHeader   UMETA(DisplayName = "Header"),
	ELogStatusNormal   UMETA(DisplayName = "Normal"),
	ELogStatusWarning  UMETA(DisplayName = "Warning"),
	ELogStatusCritical UMETA(DisplayName = "Critical"),
};


UENUM(BlueprintType)
enum ELogVerb
{
	ELogVerbNone   UMETA(DisplayName = "None"),
	ELogVerbLight   UMETA(DisplayName = "Light"),
	ELogVerbMedium   UMETA(DisplayName = "Medium"),
	ELogVerbHeavy   UMETA(DisplayName = "Heavy"),
	ELogVerbMassive   UMETA(DisplayName = "Massive"),
	ELogVerbOMFG   UMETA(DisplayName = "OMFG"),
};

UENUM(BlueprintType)
enum ELogAuth
{
	ELogAuthNone   UMETA(DisplayName = "None"),
	ELogAuthAuth   UMETA(DisplayName = "Auth"),
	ELogAuthDopl   UMETA(DisplayName = "Dopl"),
	ELogAuthAll    UMETA(DisplayName = "All"),
};

const TEnumAsByte<ELogStatus> LHEAD = ELogStatus::ELogStatusHeader;
const TEnumAsByte<ELogStatus> LNORM = ELogStatus::ELogStatusNormal;
const TEnumAsByte<ELogStatus> LWARN = ELogStatus::ELogStatusWarning;
const TEnumAsByte<ELogStatus> LCRIT = ELogStatus::ELogStatusCritical;

const TEnumAsByte<ELogVerb> VNONE = ELogVerb::ELogVerbNone;
const TEnumAsByte<ELogVerb> VLIGHT = ELogVerb::ELogVerbLight;
const TEnumAsByte<ELogVerb> VMED = ELogVerb::ELogVerbMedium;
const TEnumAsByte<ELogVerb> VHEAVY = ELogVerb::ELogVerbHeavy;
const TEnumAsByte<ELogVerb> VMASSIVE = ELogVerb::ELogVerbMassive;
const TEnumAsByte<ELogVerb> VOMFG = ELogVerb::ELogVerbOMFG;

const TEnumAsByte<ELogAuth> ANONE = ELogAuth::ELogAuthNone;
const TEnumAsByte<ELogAuth> AAUTH = ELogAuth::ELogAuthAuth;
const TEnumAsByte<ELogAuth> ADOPL = ELogAuth::ELogAuthDopl;
const TEnumAsByte<ELogAuth> AALL = ELogAuth::ELogAuthAll;

USTRUCT(BlueprintType)
struct FLogEntry
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FString Text;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TEnumAsByte<ELogAuth> Auth;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	uint8 Indent;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TEnumAsByte<ELogStatus> Status;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TEnumAsByte<ELogVerb> Verbosity;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool DataList = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float Time;

};

USTRUCT(BlueprintType)
struct FLogger
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FString ID;

	void SetID(FString InID);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TArray<FLogEntry> Entries;

	void Write(TEnumAsByte<ELogAuth> Auth, TEnumAsByte<ELogStatus> Status, TEnumAsByte<ELogVerb> Verbosity, uint8 Indent, bool DataList, FString Text);

};