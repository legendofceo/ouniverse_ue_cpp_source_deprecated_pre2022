// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../Enum/EMenuMainWins.h"
#include "MenuMainInitializer.generated.h"

USTRUCT(BlueprintType)
struct FMenuMainInitializer
{
	GENERATED_BODY()


	UPROPERTY(VisibleAnywhere)
	TEnumAsByte<EMenuMainWins> OpenToSubMenu;

};