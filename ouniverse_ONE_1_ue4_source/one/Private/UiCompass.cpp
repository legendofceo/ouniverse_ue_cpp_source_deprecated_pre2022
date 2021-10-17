// Fill out your copyright notice in the Description page of Project Settings.


#include "UiCompass.h"
#include "Camera/CameraComponent.h"
#include "APC.h"
#include "Components/CanvasPanel.h"
#include "Components/CanvasPanelSlot.h"
#include "Components/Image.h"

void UUiCompass::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
	SetDirection();
	
}