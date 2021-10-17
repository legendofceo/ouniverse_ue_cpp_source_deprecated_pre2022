// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "App/ControlEnums.h"
#include "App/ControlData.h"
#include "Control.generated.h"

class UControlRelay;
class UMaestro;

UCLASS()
class OUNIVERSE_API AControl : public APlayerController
{
	GENERATED_BODY()

	virtual void SetupInputComponent() override;

public:

	void Init(UMaestro* InMaestro);

private:

	void SetLastSource(EControlSource InSource);

	EControlSource LastSource_;

	bool bUpPressedController;
	bool bDownPressedController;

	bool bUpPressedKeyboard;
	bool bDownPressedKeyboard;

	void SendCommand(const FFKey& InCommand);
	void SendAxis(const FFAxis& InAxis);

	UMaestro* Maestro_;

public:

	UFUNCTION()
	void Up_D();

	UFUNCTION()
	void Up_U();

	UFUNCTION()
	void Down_D();

	UFUNCTION()
	void Down_U();

	UFUNCTION()
	void Left_D();

	UFUNCTION()
	void Left_U();

	UFUNCTION()
	void Right_D();

	UFUNCTION()
	void Right_U();

};
