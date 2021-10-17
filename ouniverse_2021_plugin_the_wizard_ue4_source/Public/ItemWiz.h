// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WizLog.h"
#include "ItemWiz.generated.h"


class UDataTable;
class UItemLib;


USTRUCT(Blueprintable, BlueprintType)
struct THEWIZARD_API FItemWizData
{
	GENERATED_BODY()

public:

	FItemWizData() {};

	UPROPERTY()
	TArray<FString> ItemsParsed;

	UPROPERTY()
	TArray<FString> InvalidRowNames;

	UPROPERTY()
	TArray<FString> NullSoftClasses;

};

UCLASS()
class THEWIZARD_API UItemWiz : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

		static const FName SYS;

public:

	UFUNCTION(BlueprintCallable, Category = "The Wizard|Container")
	static void BuildLib(UDataTable* DataTable, TSoftClassPtr<UItemLib> ItemLib, FString ItemDir, UPARAM(ref) FWizLog& Log, FItemWizData& Output);

};
