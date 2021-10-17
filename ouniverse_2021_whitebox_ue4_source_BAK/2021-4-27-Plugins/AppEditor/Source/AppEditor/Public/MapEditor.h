// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MapEditor.generated.h"

/**
 * 
 */

class UAppEditorLog;

UCLASS()
class APPEDITOR_API UMapEditor : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = "AppEditorUtilities")
	static void BloomMapData(FString Directory, FAssetData AppMemBlueprint, int& MapsAdded);

};
