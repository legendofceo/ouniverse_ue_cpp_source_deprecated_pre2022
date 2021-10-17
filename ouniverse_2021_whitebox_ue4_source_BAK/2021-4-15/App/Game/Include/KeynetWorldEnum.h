// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "KeynetWorldEnum.generated.h"


UENUM(BlueprintType)
enum KeynetWorldEnum
{
	KeynetWorldEnum_Inventory  UMETA(DisplayName = "Inventory"),
	KeynetWorldEnum_Party  UMETA(DisplayName = "Party"),
	KeynetWorldEnum_Max UMETA(DisplayName = "MAX"),
};