// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "UiStatics.generated.h"


UCLASS(Abstract, Blueprintable)
class OUNIVERSE_API UUiStatics : public UBlueprintFunctionLibrary
{

	GENERATED_BODY()

public:



	UFUNCTION(BlueprintCallable, Category = "UiStatics", meta = (HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject", DisplayName = "PlaySoundUI"))
	static void PlaySound(USoundBase* Sound, UObject* WorldContextObject, bool bBypassMute, float  ExtraVolumeModifier, float  ExtraPitchModifier, float PitchRange);

	static void FocusWidget(UUserWidget* InWidget);

};