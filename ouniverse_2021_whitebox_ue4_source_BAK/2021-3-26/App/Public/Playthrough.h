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

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	UStory* ActiveStory;

	UStory* GetActiveStory();
	
	void SetActiveStory(UStory* Story);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "#Set Active Story"))
	void SetActiveStoryBP(UStory* Story, UStory*& StoryR);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TMap<int, UStory*> Stories;

	UFUNCTION(BlueprintCallable)
	void AddStory(UStory* Story);

	UStory* GetStory(int StoryKey);


	UFUNCTION(Category = "Playthrough", BlueprintCallable, BlueprintPure, meta = (DisplayName = "#Story"))
	static void GetStoryBP(int Key, UStory*& Story);

};
