// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Info.h"
#include "Marshal/Marshal.h"
#include "Playthrough.generated.h"

/**
 * 
 */

class UStory;


UCLASS(Abstract, BlueprintType, Blueprintable)
class APP_API APlaythrough : public AInfo
{
	GENERATED_BODY()

public:

	APlaythrough();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FMarshal Marshal;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	UStory* ActiveStory;

	UStory* GetActiveStory();
	
	void SetActiveStory(UStory* Story);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "#Set Active Story"))
	void SetActiveStoryBP(UStory* Story, UStory*& StoryR);
};
