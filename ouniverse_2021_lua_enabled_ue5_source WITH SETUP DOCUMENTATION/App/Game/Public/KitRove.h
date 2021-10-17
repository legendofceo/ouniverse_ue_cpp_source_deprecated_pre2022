// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kit.h"
#include "KitRove.generated.h"

class AActraExHuman;
class UBT;
class UAX;

UCLASS()
class APP_API UKitRove : public UKit
{
	GENERATED_BODY()

public:

	void Init(AActraExHuman* InActraExHuman);

	UPROPERTY(VisibleAnywhere)
	AActraExHuman* ActraExHuman;


	virtual void Connect() override;

	virtual void Disconnect() override;

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float BaseTurnRate = 45.0;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float BaseLookUpRate = 45.0;

	UFUNCTION()
	void MainMenu(UBT* BT);

	UFUNCTION()
	void PartyUp(UBT* BT);

	UFUNCTION()
	void PartyDown(UBT* BT);

	UFUNCTION()
	void MoveForwardGamepad(UAX* AX);

	UFUNCTION()
	void MoveRightGamepad(UAX* AX);

	UFUNCTION()
	void TurnAtRate(UAX* AX);

	UFUNCTION()
	void LookUpAtRate(UAX* AX);

};

