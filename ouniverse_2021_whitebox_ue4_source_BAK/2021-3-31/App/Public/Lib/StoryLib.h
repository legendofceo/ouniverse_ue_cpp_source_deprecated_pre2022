// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Lib/Lib.h"
#include "StoryLib.generated.h"


class UStory;

UCLASS(Abstract, BlueprintType, Blueprintable)
class APP_API UStoryLib : public ULib
{
	GENERATED_BODY()

public:

	static UStoryLib* Get();

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = ":StoryLib"))
	static void GetStoryLibBP(UStoryLib*& StoryLib);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TMap<int, UStory*> Stories;

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "#RegStory"))
	void RegStory(TSoftClassPtr<UStory> StoryClass, FString MarshalKey, UPARAM(ref) UStory*& Param);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "#StorySCP"))
	void StorySCP(TSoftClassPtr<UStory>C, TSoftClassPtr<UStory>& R);

	void Init() override;
	void PostAsync() override;
};
