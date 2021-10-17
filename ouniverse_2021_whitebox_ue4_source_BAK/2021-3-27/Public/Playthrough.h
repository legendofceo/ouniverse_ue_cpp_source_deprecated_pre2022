// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Info.h"
#include "Marshal/Marshal.h"
#include "Playthrough.generated.h"

/**
 * 
 */

class AStory;


UCLASS(Abstract, BlueprintType, Blueprintable)
class APP_API APlaythrough : public AInfo
{
	GENERATED_BODY()

public:

	APlaythrough();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FMarshalNew Marshal;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	AStory* ActiveStory;

	AStory* GetActiveStory();
	
	void SetActiveStory(AStory* Story);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "#Set Active Story"))
	void SetActiveStoryBP(AStory* Story, AStory*& StoryR);
};
