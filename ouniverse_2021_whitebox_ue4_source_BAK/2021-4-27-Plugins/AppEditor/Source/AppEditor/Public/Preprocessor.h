// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Editor/Blutility/Classes/EditorUtilityWidget.h"
#include "Preprocessor.generated.h"

/**
 * 
 */


 // SUPER WARNING
 /*===========================================================================
   _____ __  ______  __________     _       _____    ____  _   _______   ________
  / ___// / / / __ \/ ____/ __ \   | |     / /   |  / __ \/ | / /  _/ | / / ____/
  \__ \/ / / / /_/ / __/ / /_/ /   | | /| / / /| | / /_/ /  |/ // //  |/ / / __
 ___/ / /_/ / ____/ /___/ _, _/    | |/ |/ / ___ |/ _, _/ /|  // // /|  / /_/ /
/____/\____/_/   /_____/_/ |_|     |__/|__/_/  |_/_/ |_/_/ |_/___/_/ |_/\____/


If you create a NEW preprocessor EditorWidget it will just become a normal blueprint widget
The only way to make this work is to first create an EditorWidget then reparent it to the Preprocessor class.

 ===========================================================================*/

class UDataTable;
class UAppEditorLog;
class UGameData;

UCLASS()
class APPEDITOR_API UPreprocessor : public UEditorUtilityWidget
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = "AppEditorUtilities")
	static void ProcessEquipmentSlots(TSoftClassPtr<UGameData> GameDataBP, UDataTable* DataTable, UPARAM(ref) FLogPP& Log, int& EquipmentSlotsNum);

};
