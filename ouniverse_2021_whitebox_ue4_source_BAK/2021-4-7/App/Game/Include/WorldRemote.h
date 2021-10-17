// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Remote.h"
#include "AreaAddress.h"
#include "Tally.h"
#include "Log.h"
#include "WorldRemote.generated.h"


class UAreaManager;
class APartyRemote;
class UWorldPort;

class UPartyHandle;
struct FZone;


UCLASS(BlueprintType, Blueprintable)
class APP_API AWorldRemote : public ARemote
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	AWorldRemote();

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FLogger Log;

	static AWorldRemote* Get();

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = ":MythNexus"))
	static void GetStoryMngBP(AWorldRemote*& StoryMng);

	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
	FTally Tally;
	
	void EnterWorld();
	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "@EnterWorld"))
	void EnterWorldBP();

	UFUNCTION()
	void EnterWorld_Tally(int TID);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	APartyRemote* PartyRemote;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UAreaManager* AreaManager;


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TArray<UWorldPort*> Ports;

public:


	UPartyHandle* GetActivePartyHandle();

	void LoadZone(FZone* Zone);

};
