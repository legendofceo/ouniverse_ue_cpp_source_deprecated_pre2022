// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommandsMenu.generated.h"

UENUM(BlueprintType)
enum class CommandMenu : uint8
{
	None  UMETA(DisplayName = "None"),
	Up  UMETA(DisplayName = "Up"),
	Down  UMETA(DisplayName = "Down"),
	Left  UMETA(DisplayName = "Left"),
	Right  UMETA(DisplayName = "Right"),
	Accept  UMETA(DisplayName = "Accept"),
	Cancel  UMETA(DisplayName = "Cancel"),
	MAX UMETA(DisplayName = "MAX"),
};