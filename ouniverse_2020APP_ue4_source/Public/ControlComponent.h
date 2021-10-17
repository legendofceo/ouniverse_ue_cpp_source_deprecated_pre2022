// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ControlComponent.generated.h"

/**
 * 
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnKeyInput);

UCLASS(Blueprintable, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ETREIAAPP_API UControlComponent : public UActorComponent
{
	GENERATED_BODY()

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	AActor* Actor;

	UFUNCTION(BlueprintCallable)
	void BindComplex();

	UFUNCTION()
	void PadA_Pressed();
	UFUNCTION()
	void PadA_Released();

	UFUNCTION()
	void PadB_Pressed();
	UFUNCTION()
	void PadB_Released();

	UFUNCTION()
	void PadX_Pressed();
	UFUNCTION()
	void PadX_Released();

	UFUNCTION()
	void PadY_Pressed();
	UFUNCTION()
	void PadY_Released();

	UPROPERTY(BlueprintAssignable)
	FOnKeyInput OnPadExPressed;
	UPROPERTY(BlueprintAssignable)
	FOnKeyInput OnPadExReleased;

	UPROPERTY(BlueprintAssignable)
	FOnKeyInput OnPadCirclePressed;
	UPROPERTY(BlueprintAssignable)
	FOnKeyInput OnPadCircleReleased;

	UPROPERTY(BlueprintAssignable)
	FOnKeyInput OnPadSquarePressed;
	UPROPERTY(BlueprintAssignable)
	FOnKeyInput OnPadSquareReleased;
	
	UPROPERTY(BlueprintAssignable)
	FOnKeyInput OnPadTrianglePressed;
	UPROPERTY(BlueprintAssignable)
	FOnKeyInput OnPadTriangleReleased;

	UPROPERTY(BlueprintAssignable)
	FOnKeyInput OnPadUpPressed;
	UPROPERTY(BlueprintAssignable)
	FOnKeyInput OnPadUpReleased;

	UPROPERTY(BlueprintAssignable)
	FOnKeyInput OnPadDownPressed;
	UPROPERTY(BlueprintAssignable)
	FOnKeyInput OnPadDownReleased;

	UPROPERTY(BlueprintAssignable)
	FOnKeyInput OnPadLeftPressed;
	UPROPERTY(BlueprintAssignable)
	FOnKeyInput OnPadLeftReleased;


	UPROPERTY(BlueprintAssignable)
	FOnKeyInput OnPadRightPressed;
	UPROPERTY(BlueprintAssignable)
	FOnKeyInput OnPadRightReleased;

};