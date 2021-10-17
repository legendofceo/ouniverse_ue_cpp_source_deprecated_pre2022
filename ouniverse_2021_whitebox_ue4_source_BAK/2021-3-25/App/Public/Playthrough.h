// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Playthrough.generated.h"

/**
 * 
 */

class UStory;
struct FPlaythroughMem;

UCLASS()
class APP_API UPlaythrough : public UObject
{
	GENERATED_BODY()

public:

	FPlaythroughMem* Mem;

	void SetMem(FPlaythroughMem* PlaythroughMem);

	UStory* ActiveStory;

	UStory* GetActiveStory();

	void SetActiveStory(UStory* Story);

};
