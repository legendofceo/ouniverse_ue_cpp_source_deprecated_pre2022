// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Remote.h"
#include "AppRemote.generated.h"


class UAppPort;
class AWorldRemote;
class AAppController;
class UAppPlayer;

UCLASS(BlueprintType, Blueprintable)
class APP_API AAppRemote : public ARemote
{
	GENERATED_BODY()

public:

	AAppRemote();

	static AAppRemote* Get();

	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	TArray<UAppPort*> Ports;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	AWorldRemote* WorldRemote;


	/** Array of AppControllers that are currently connected, Stored only for proof. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TArray<AAppController*> AppControllers;


	static const int MaxPlayers = 4;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int MaxPlayersDisplay;


	/**
	* When players join the new controller (AppController) is reported to the AppMode.
	* AppMode assigns a player to the controller once reported.
	*/

	UFUNCTION()
	void ReceivePlayer(AAppController* AppController);

	/**
	* The BaseController is the first AppController to connect. This is always
	* always present as it cannot be disconnected.
	*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	AAppController* BaseController;

	/** Add a local player to the game. */
	void AddLocalPlayer();
};
