// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WizLog.h"
#include "ActraWiz.generated.h"

/**
 *
 */

class UDataTable;
class UPreprocessorWizLog;

UCLASS()
class THEWIZARD_API UActraWiz : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

		static const FName SYS;

public:

	UFUNCTION(BlueprintCallable, Category = "The Wizard|Container")
	static void BuildLib();

};
