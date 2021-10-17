// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "Hero.generated.h"

class USkeletalMeshComponent;
class USpringArmComponent;
class UCameraComponent;

UCLASS()
class OUNIVERSE_API AHero : public ACharacter
{
	GENERATED_BODY()

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;


public:

	AHero();

	//AVip();
	//ANpc();


	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	USkeletalMeshComponent* Skeleton_;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	USpringArmComponent* OrbitBoom_;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UCameraComponent* OrbitCam_;

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		float BaseLookUpRate;


	float CamZoomGoal;

public:

	void MoveX(float Value);
	void MoveY(float Value);
	void TurnY(float Value);
	void LookX(float Value);
	void Zoom(float AxisValue);
};