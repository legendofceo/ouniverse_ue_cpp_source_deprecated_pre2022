// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LogPP.h"
#include "CompanionEditor.generated.h"

/**
 * 
 */

class UDataTable;
class UAppEditorLog;

UCLASS()
class APPEDITOR_API UCompanionEditor : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	static const FName SYS;

public:

	UFUNCTION(BlueprintCallable, Category = "AppEditorUtilities")
	static void ProcessCompanionData(FString Directory, UDataTable* DataTable, UPARAM(ref) FLogPP& Log, int& DirNum, int& TableNum);

};
