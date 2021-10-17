// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EKeynets.generated.h"

UENUM(BlueprintType)
enum EKeynets
{
	EKeynets_Menu  UMETA(DisplayName = "Menu"),
	EKeynets_World  UMETA(DisplayName = "World"),
	EKeynets_Max UMETA(DisplayName = "MAX"),
};
