// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "KeynetMenuEnum.generated.h"

UENUM(BlueprintType)
enum KeynetMenuEnum
{
	KeynetMenuEnum_Accept  UMETA(DisplayName = "Accept"),
	KeynetMenuEnum_Cancel  UMETA(DisplayName = "Cancel"),
	KeynetMenuEnum_TabLeft  UMETA(DisplayName = "TabLeft"),
	KeynetMenuEnum_TabRight  UMETA(DisplayName = "TabRight"),
	KeynetMenuEnum_BumpLeft  UMETA(DisplayName = "BumpLeft"),
	KeynetMenuEnum_BumpRight  UMETA(DisplayName = "BumpRight"),
	KeynetMenuEnum_Max UMETA(DisplayName = "MAX"),
};