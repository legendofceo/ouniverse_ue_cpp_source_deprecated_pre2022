// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MemEditor.generated.h"

/**
 * 
 */

class UAppEditorLog;

UCLASS()
class APPEDITOR_API UMemEditor : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintCallable, Category = "AppEditorUtilities")
	static void BloomMemFlags(FString Directory, FAssetData AppMemBlueprint);
};