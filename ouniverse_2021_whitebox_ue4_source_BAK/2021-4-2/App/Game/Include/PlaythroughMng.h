// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Nexus.h"
#include "PlaythroughMng.generated.h"


class UStory;

UCLASS(Abstract, BlueprintType, Blueprintable)
class APP_API APlaythroughMng : public ANexus
{
	GENERATED_BODY()

public:

	APlaythroughMng();

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "#Set Active Story"))
	void SetActiveStory(UStory* InStory);

	void NewGame();
	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "@NewGame"))
	void NewGameBP();

	void StartGame();
	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "@StartGame"))
	void StartGameBP();

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	UStory* ActiveStory = NULL;

};
