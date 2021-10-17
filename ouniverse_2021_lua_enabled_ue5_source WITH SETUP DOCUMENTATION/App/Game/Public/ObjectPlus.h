// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ObjectPlus.generated.h"


UCLASS(Blueprintable)
class APP_API UObjectPlus : public UObject
{
	GENERATED_BODY()

public:

public:
    // Allows the Object to use BP_Functions
    class UWorld* GetWorld() const;
    class ULevel* GetLevel() const;

};