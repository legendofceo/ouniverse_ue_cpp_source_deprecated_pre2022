// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Nexus.h"
#include "AreaAddress.h"
#include "StoryMng.generated.h"


class UStory;
class UArea;

struct FParty;
class UPartyHandle;

struct FZone;

UCLASS(Abstract, BlueprintType, Blueprintable)
class APP_API ACosmNexus : public ANexus
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	ACosmNexus();

public:

	static ACosmNexus* Get();

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = ":MythNexus"))
	static void GetStoryMngBP(ACosmNexus*& StoryMng);

	virtual void BeginPlay() override;

	void StartStory(UStory* InStory);



	void StartGame();
	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "@StartGame"))
	void StartGameBP();



	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UStory* ActiveStory;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FAreaAddress PendingAreaAddress;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FAreaAddress AreaAddress;


	void ChangeArea(UArea* NextArea, FAddress NextAddress);

	UFUNCTION()
	void AreaUnloaded();


	FZone* ActiveZone;

	void LoadZone(FZone* Zone);






	FParty* ActiveParty;

	void LoadParty(FParty* InActiveParty);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UPartyHandle* ActivePartyHandle;

	UPROPERTY()
	FDelegate OnLoadComplete;

	UFUNCTION()
	void StartStoryLoadPartyComplete();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "#Engage Party"))
	void EngagePartyBP();

};
