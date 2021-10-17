
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "StoryKeys.generated.h"



struct StoryMem
{

};

UCLASS()
class APP_API UStoryKeys : public UObject
{
	GENERATED_BODY()

public:

	static const int Primary;

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "$Story Primary"))
	static void PrimaryKey(int& Key);

};