// Fill out your copyright notice in the Description page of Project Settings.

#include "UiStatics.h"
#include "../System/Major.h"
#include "Kismet/GameplayStatics.h"


void UUiStatics::PlaySound(USoundBase* Sound, UObject* WorldContextObject, bool bBypassMute, float  ExtraVolumeModifier, float  ExtraPitchModifier, float PitchRange)
{
	UGameplayStatics::PlaySound2D(WorldContextObject, Sound, 1.0f, 1.0f, 0.0f);
}

void UUiStatics::FocusWidget(UUserWidget* InWidget)
{
	//InWidget->SetUserFocus(UMajor::Get()->Control());
}