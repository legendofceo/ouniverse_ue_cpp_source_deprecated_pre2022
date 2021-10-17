// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EKeynetWorld.generated.h"


UENUM(BlueprintType)
enum EKeynetWorld
{
	EKeynetWorld_Inventory  UMETA(DisplayName = "Inventory"),
	EKeynetWorld_Party  UMETA(DisplayName = "Party"),
	EKeynetWorld_Max UMETA(DisplayName = "MAX"),
};