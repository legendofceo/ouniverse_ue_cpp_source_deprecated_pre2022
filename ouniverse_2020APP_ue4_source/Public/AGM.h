// Fill out your copyright notice in the Description page of Project Settings.

/**

## Mode

Extends UE4's AGameMode and holds default game mode assignments.

#### Current Swaps:
* APlayerController to AControLUE
* AHud to AHudUE

*/

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "AGM.generated.h"

class AAvatar;
class AActra;
class APC;
class UMem;
class AParty;

UCLASS()
class AGM : public AGameModeBase
{
	GENERATED_BODY()
	
public:

	AGM();

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	static AGM* GetGM();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	AParty* Party;

	UFUNCTION(BlueprintCallable)
	void AddPlayer(APC* PlayerController);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TArray<APC*> Players;

	UFUNCTION(BlueprintCallable)
	void SpawnParty();

	UFUNCTION()
	void NewGame();

	UFUNCTION()
	void LoadGame();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UMem* Memory;

};
