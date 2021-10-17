// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Info.h"
#include "AppPlayer.generated.h"

class AAppController;
class ACam;
class AAppPro;
class UCameraComponent;
class USceneComponent;
class UInputButtonEvent;

UCLASS()
class APP_API AAppPlayer : public AInfo
{
	GENERATED_BODY()
	
public:
	// Sets default values for this component's properties
	AAppPlayer();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	USceneComponent* Root;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	AAppController* AppController = NULL;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	ACam* Cam = NULL;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	AAppPro* AppPro = NULL;

public:

	bool IsOccupied();

	void PlayerSignBT(UInputButtonEvent* BT);
	void PlayerSignAX(UInputButtonEvent* AX);

public:

	void SetAppController(AAppController* AppController);

	void SetAppPro(AAppPro* InAppPro);

	UFUNCTION(BlueprintCallable)
	void SetCamTarget(UCameraComponent* CamTarget);


};
