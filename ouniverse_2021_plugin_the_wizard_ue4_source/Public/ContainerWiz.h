// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WizLog.h"
#include "ContainerWiz.generated.h"

/**
 * 
 */

class UDataTable;
class UContainerLib;

USTRUCT(Blueprintable, BlueprintType)
struct THEWIZARD_API FContainerWizData
{
	GENERATED_BODY()

public:

	FContainerWizData() {};


};

UCLASS()
class THEWIZARD_API UContainerWiz : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	static const FName SYS;

public:

	UFUNCTION(BlueprintCallable, Category = "The Wizard|Container")
	static void BuildLib(UDataTable* DataTable, TSoftClassPtr<UContainerLib> ContainerLib, FString ContainerDir, UPARAM(ref) FWizLog& Log, FContainerWizData& Output);

};
