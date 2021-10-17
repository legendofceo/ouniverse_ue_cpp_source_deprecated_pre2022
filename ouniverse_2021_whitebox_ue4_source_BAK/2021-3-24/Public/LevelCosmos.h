// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"
#include "LevelCosmos.generated.h"

/**
 * 
 */

class ULevelStreamingDynamic;

UCLASS()
class APP_API ALevelCosmos : public ALevelScriptActor
{
	GENERATED_BODY()

public:

	//~=============================================================================
	// Level Steaming

	/** AppMode does centralized handeling of all Level Streaming. */

	/** Stream Dynamic pointer storage. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	ULevelStreamingDynamic* StreamedDynamic;

	/** Begins streaming a level from a SoftPointer. */
	UFUNCTION(BlueprintCallable)
	void DoMapStream(TSoftObjectPtr<UWorld> Map);

	/** Lazy Loaded continuation of MapStream */
	UFUNCTION()
	void DoMapStreamLL();

};
