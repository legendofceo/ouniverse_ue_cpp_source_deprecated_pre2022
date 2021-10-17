// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PlayerMng.generated.h"

class AAppController;
class AAppMode;

UCLASS(Abstract, BlueprintType, Blueprintable, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class APP_API UPlayerMng : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UPlayerMng();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void Init(AAppMode* InAppMode);

	void InitII() {};

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	AAppMode* AppMode;

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
