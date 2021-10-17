// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Mng/Mng.h"
#include "StoryMng.generated.h"


class UStory;
class UPartyHandle;
class UArea;
class UAreaSwitch;
struct FParty;

UCLASS(Abstract, BlueprintType, Blueprintable)
class APP_API AStoryMng : public AManagerActor
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	AStoryMng();

public:

	static AStoryMng* Get();

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = ":StoryMng"))
	static void GetStoryMngBP(AStoryMng*& StoryMng);

	virtual void BeginPlay() override;

	void StartStory(UStory* InStory);

	UFUNCTION()
	void StartStoryLoadPartyComplete();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UStory* ActiveStory;

	FParty* ActiveParty;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	UPartyHandle* ActivePartyHandle;


	UFUNCTION(BlueprintCallable, meta = (DisplayName = "#Add Companion To Party"))
	void AddCompanionToParty(UStory* Story, UCompanion* Companion);

};
