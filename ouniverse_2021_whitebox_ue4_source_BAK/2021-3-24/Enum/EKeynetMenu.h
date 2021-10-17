// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EKeynetMenu.generated.h"

UENUM(BlueprintType)
enum EKeynetMenu
{
	EKeynetMenu_Accept  UMETA(DisplayName = "Accept"),
	EKeynetMenu_Cancel  UMETA(DisplayName = "Cancel"),
	EKeynetMenu_TabLeft  UMETA(DisplayName = "TabLeft"),
	EKeynetMenu_TabRight  UMETA(DisplayName = "TabRight"),
	EKeynetMenu_BumpLeft  UMETA(DisplayName = "BumpLeft"),
	EKeynetMenu_BumpRight  UMETA(DisplayName = "BumpRight"),
	EKeynetMenu_Max UMETA(DisplayName = "MAX"),
};