// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CompanionActor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FEmbodyComplete);

class UCompanion;
class USpringArmComponent;
class UCameraComponent;

class UCompanionRemote;

UCLASS()
class APP_API ACompanionActor : public ACharacter
{
	GENERATED_BODY()

	static const FName SYS;

public:
	// Sets default values for this character's properties
	ACompanionActor();

	/** Follow camera */

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UCompanion* Companion;

	UFUNCTION()
	void Become(UCompanion* MCompanion);

	UFUNCTION(BlueprintCallable)
	void EmbodyComplete();

	UPROPERTY(BlueprintAssignable)
	FEmbodyComplete OnBecomeComplete;

	
	void Engage(UCompanionRemote* Remote);



	UFUNCTION(BlueprintCallable)
	void MoveForward(float Value);
	UFUNCTION(BlueprintCallable)
	void MoveRight(float Value);


};
