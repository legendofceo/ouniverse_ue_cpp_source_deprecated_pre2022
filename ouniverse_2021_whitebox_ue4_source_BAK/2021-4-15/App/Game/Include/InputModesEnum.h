// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputModesEnum.generated.h"

UENUM(BlueprintType)
enum InputModesEnum
{
	InputModesEnum_MAK  UMETA(DisplayName = "Mouse & Keyboard"),
	InputModesEnum_PAD  UMETA(DisplayName = "Gamepad"),
};