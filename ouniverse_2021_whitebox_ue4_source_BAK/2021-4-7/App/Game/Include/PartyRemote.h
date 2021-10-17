// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Remote.h"
#include "Delegate.h"
#include "PartyRemote.generated.h"

class URaidManager;

class UPartyHandle;

struct FTally;

struct FParty;
struct FRaid;

class APlayerPort;
class UPartyPort;

class ACompanionRemote;

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

	APartyRemote();

	static const int TID_Buffer;

	virtual void BeginPlay() override;

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

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TArray<ACompanionRemote*> CompanionRemotes;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TArray<UPartyPort*> PartyPorts;

	void Buffer(FTally* Tally);

	UFUNCTION()
	void BufferComplete();

	UPROPERTY()
	FDelegateInt OnBufferComplete;

	void Engage(APlayerPort* InPlayerPort);

};
