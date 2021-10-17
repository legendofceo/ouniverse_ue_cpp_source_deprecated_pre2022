// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Manager.h"
#include "Delegate.h"
#include "PartyManager.generated.h"

class URaidManager;
class UPartyState;

class UPartyHandle;

struct FTally;

struct FParty;
struct FRaid;


UENUM(BlueprintType)
enum EPartyMode
{
	EPartyMdoeSolo	UMETA(DisplayName = "Solo"),
	EPartyModeParty	UMETA(DisplayName = "Party"),
	EPartyModeRaid		UMETA(DisplayName = "Raid"),
};

UCLASS()
class APP_API UPartyManager : public UManager
{
	GENERATED_BODY()

public:

	UPartyManager();

	void Init();

	static const int TID_Buffer;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UPartyState* PartyState;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int PartyMaxSize;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int RaidMaxParties;

	void Connect(FParty* PartyData, FRaid* RaidData);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TEnumAsByte<EPartyMode> PartyMode;

	void SetPartyMode(TEnumAsByte<EPartyMode> InPartyMode);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UPartyHandle* ActiveParty;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UPartyHandle* Party;
	
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	URaidManager* RaidManager;


	void Buffer(FTally* Tally);

	UFUNCTION()
	void BufferComplete();

	void SetActiveParty(UPartyHandle* InActiveParty);

	UPROPERTY()
	FDelegateInt OnBufferComplete;


};
