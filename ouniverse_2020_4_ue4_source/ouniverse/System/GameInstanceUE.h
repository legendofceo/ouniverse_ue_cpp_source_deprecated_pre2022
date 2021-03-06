// Fill out your copyright notice in the Description page of Project Settings.

/**

## ControlUE

AControlUE is an exension to UE4's APlayerController.

> Currently does nothing as the SInputCatch and InputManager are doing most of it's responsibilities.

 */

#pragma once

#include "Engine/GameInstance.h"
#include "GameInstanceUE.generated.h"


class UMajor;

UCLASS()
class OUNIVERSE_API UGameInstanceUE : public UGameInstance
{
	GENERATED_BODY()

public:

	UPROPERTY()
	UMajor* Major_;

};