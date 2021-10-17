// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Marshal.h"
#include "Delegate.h"
#include "Playthrough.generated.h"

/**
 * 
 */

class UStory;


UCLASS(Abstract, BlueprintType, Blueprintable)
class APP_API UPlaythrough : public UObject
{
	GENERATED_BODY()

public:

	static UPlaythrough* Get();

	UPlaythrough();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FMarshal Marshal;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	UStory* ActiveStory;

	UStory* GetActiveStory();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "#Set Active Story"))
	void SetActiveStory(UStory* InStory);
		
	void Init();

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "@Init"))
	void InitBP();

	void InitPostLib();
	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "@InitPostLib"))
	void InitPostLibBP();

	UPROPERTY()
	FDelegateObj OnInitComplete;
};
