// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Remote.h"
#include "Delegate.h"
#include "PartyManager.generated.h"

class URaidManager;

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
class APP_API APartyRemote : public ARemote
{
	GENERATED_BODY()

public:

	static const int TID_Buffer;

	void Init();

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

	UPROPERTY()
	FDelegateInt OnBufferComplete;

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "#Engage Party"))
	void EngagePartyBP();

};
