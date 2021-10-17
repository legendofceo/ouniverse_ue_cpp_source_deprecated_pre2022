// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "base.h"
#include "control_list.h"
#include "control_event.h"
#include "control_ue.generated.h"

class UInputListener;

UCLASS()
class AControlUE : public APlayerController
{
	GENERATED_BODY()

	//virtual void PlayerTick(float DeltaTime) override;

	//virtual void SetupInputComponent() override;

public:

	AControlUE() {};

	static AControlUE* Initialize(AActor* WorldActor);
	static AControlUE* Get();

	void Constructor();

	void BindKeyboard(UInputListener* Listener, EStrokeKB Stroke, bool bPressed);

	UPROPERTY(Category = "0 Details", VisibleAnywhere, BlueprintReadOnly)
	int32 ControlIndex;

	UPROPERTY(Category = "0 Details", VisibleAnywhere)
	FControlButton Escape;

	UPROPERTY(Category = "0 Details", VisibleAnywhere)
	bool bMouseMode;

	UFUNCTION(BlueprintCallable)
	void SetMouseMode(bool bOn);

};