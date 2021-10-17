// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Protocol.h"
#include "AreaAddress.h"
#include "Tally.h"
#include "Log.h"
#include "MythPro.generated.h"

class USoftServe;

class UPartyPro;

class UAreaManager;
class UPartyManager;
class UPartyHandle;


struct FZone;

UENUM(Blueprintable)
enum class EMythPros : uint8
{
	None		UMETA(DisplayName = "None"),
	Basic		UMETA(DisplayName = "Basic"),
	Party		UMETA(DisplayName = "Party"),
};

UCLASS(BlueprintType, Blueprintable)
class APP_API UMythPro : public UProtocol
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UMythPro();

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FLogger Log;

	static UMythPro* Get();

	void Init();
	
	UFUNCTION()
	void Init_SS(USoftServe* SoftServe);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UPartyPro* PartyPro;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UPartyManager* PartyManager;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UAreaManager* AreaManager;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	USoftServe* SS;

	UPROPERTY(VisibleAnywhere)
	FTally Tally;
	
	void Engage();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	EMythPros Pro;

	UFUNCTION()
	void EnterWorld_Tally(int TID);


public:


	UPartyHandle* GetActivePartyHandle();

	void LoadZone(FZone* Zone);

};
