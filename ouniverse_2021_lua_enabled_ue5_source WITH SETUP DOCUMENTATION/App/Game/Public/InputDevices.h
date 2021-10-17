// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputDevices.generated.h"

UENUM(BlueprintType)
enum class InputDevice : uint8
{
	Mouse  UMETA(DisplayName = "Mouse"),
	Keyboard  UMETA(DisplayName = "Keyboard"),
	Gamepad  UMETA(DisplayName = "Gamepad"),
};