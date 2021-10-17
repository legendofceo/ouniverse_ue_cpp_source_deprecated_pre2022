// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "LogComponent.generated.h"


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

USTRUCT(BlueprintType)
struct FLogEntry
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FString Text;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	uint8 Indent;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TEnumAsByte<ELogVerb> Verbosity;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TEnumAsByte<ELogStatus> Status;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool DataList = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float Time;

};


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class APP_API ULogComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	ULogComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TArray<FLogEntry> Entries;

	void Write(TEnumAsByte<ELogStatus> Status, TEnumAsByte<ELogVerb> Verbosity, uint8 Indent, bool DataList, FString Text);
};
