// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Nexus.h"
#include "PlayerMng.generated.h"

class AAppController;


UCLASS(Abstract, BlueprintType, Blueprintable)
class APP_API APlayerMng : public ANexus
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	APlayerMng();


	static APlayerMng* Get();

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = ":PlayerMng"))
	static void GetPlayerMngBP(APlayerMng*& PlayerMng);

	virtual void BeginPlay() override;

	/**
	* When players join the new controller (AppController) is reported to the AppMode.
	* AppMode assigns a player to the controller once reported.
	*/
	UFUNCTION(BlueprintCallable)
	void NewPlayerConnection(AAppController* AppController);

	/**
	* The BaseController is the first AppController to connect. This is always
	* always present as it cannot be disconnected.
	*/
	UPROPERTY(Category = "Players Management", VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	AAppController* BaseController;

	/** Array of AppControllers that are currently connected for debugging. */
	UPROPERTY(Category = "Players Management", VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TArray<AAppController*> AppControllers;


	/** Add a local player to the game. */
	void AddLocalPlayer();

};
