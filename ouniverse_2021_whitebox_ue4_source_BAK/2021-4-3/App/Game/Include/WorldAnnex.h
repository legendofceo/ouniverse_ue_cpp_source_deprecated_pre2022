// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Annex.h"
#include "AreaAddress.h"
#include "Tally.h"
#include "WorldAnnex.generated.h"


class UAreaManager;
class UPartyManager;

class UPartyHandle;
struct FZone;

UCLASS(Abstract, BlueprintType, Blueprintable)
class APP_API UWorldAnnex : public UAnnex
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UWorldAnnex();

public:

	static UWorldAnnex* Get();

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = ":MythNexus"))
	static void GetStoryMngBP(UWorldAnnex*& StoryMng);

	void Init();

	UPROPERTY(VisibleAnywhere)
	FTally Tally;
	
	void EnterWorld();
	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "@EnterWorld"))
	void EnterWorldBP();

	UFUNCTION()
	void EnterWorld_Tally(int TID);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UPartyManager* PartyManager;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UAreaManager* AreaManager;

public:


	UPartyHandle* GetActivePartyHandle();

	void LoadZone(FZone* Zone);

};
