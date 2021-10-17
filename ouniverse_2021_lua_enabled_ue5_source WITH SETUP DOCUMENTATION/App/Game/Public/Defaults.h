// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Defaults.generated.h"

/**
 * 
 */



UCLASS()
class APP_API UDefaults : public UObject
{
	GENERATED_BODY()

public:
	static const FString MyDocsFolderName;

	static const int PartyMaxSize;

	static const int RaidMaxParties;

};