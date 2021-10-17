// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EInputMode.generated.h"

UENUM(BlueprintType)
enum EInputMode
{
	EInputMode_MAK  UMETA(DisplayName = "Mouse & Keyboard"),
	EInputMode_PAD  UMETA(DisplayName = "Gamepad"),
};