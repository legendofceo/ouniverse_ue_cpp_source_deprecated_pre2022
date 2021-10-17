// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AppMemInitializer.generated.h"

/**
 * 
 */

class UParty;
class UStory;
class UCompanion;
class UPlaythrough;

UCLASS(Abstract,BlueprintType, Blueprintable)
class APP_API UAppMemInitializer : public UObject
{
	GENERATED_BODY()

	UAppMemInitializer() {};

public:


	UPROPERTY(category = "Story", EditAnywhere, BlueprintReadOnly)
	TSoftClassPtr<UParty> PartyClass;

	UPROPERTY(category = "Story", EditAnywhere, BlueprintReadOnly)
	TSoftClassPtr<UPlaythrough> PlaythroughClass;

	//Story Classes

	UPROPERTY(category = "Story", EditAnywhere, BlueprintReadOnly)
	TSoftClassPtr<UStory> StoryPrimaryClass;

	//Companion Classes

	UPROPERTY(category = "Companion", EditAnywhere, BlueprintReadOnly)
	TSoftClassPtr<UCompanion> CompanionFioneClass;

	UPROPERTY(category = "Companion", EditAnywhere, BlueprintReadOnly)
	TSoftClassPtr<UCompanion> CompanionMishaClass;

};
