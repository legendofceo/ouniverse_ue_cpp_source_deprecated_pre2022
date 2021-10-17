// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ControlEnums.generated.h"


UENUM(BlueprintType)
enum class EControlSource : uint8
{
	Undefined 		UMETA(DisplayName = "Undefined"),
	Keyboard 		UMETA(DisplayName = "Keyboard"),
	Controller 		UMETA(DisplayName = "Controller"),
	Touch			UMETA(DisplayName = "Touch"),
	Simulated		UMETA(DisplayName = "Simulated")
};

UENUM(BlueprintType)
enum class ECommand : uint8
{
	Undefined	UMETA(DisplayName = "Undefined"),
	Up			UMETA(DisplayName = "Up"),
	Down 		UMETA(DisplayName = "Down"),
	Left 		UMETA(DisplayName = "Left"),
	Right		UMETA(DisplayName = "Right"),
};

UENUM(BlueprintType)
enum class EControlAxis : uint8
{
	Undefined	UMETA(DisplayName = "Undefined"),
	Up			UMETA(DisplayName = "Undefined"),
	Down 		UMETA(DisplayName = "Keyboard"),
	Left 		UMETA(DisplayName = "Controller"),
	Right		UMETA(DisplayName = "Touch"),
};