// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "KeynetsEnum.generated.h"

UENUM(BlueprintType)
enum KeynetsEnum
{
	KeynetsEnum_Menu  UMETA(DisplayName = "Menu"),
	KeynetsEnum_World  UMETA(DisplayName = "World"),
	KeynetsEnum_Max UMETA(DisplayName = "MAX"),
};
