// Fill out your copyright notice in the Description page of Project Settings.


#include "UiHudElect.h"
#include "Components/NamedSlot.h"



void UUiHudElect::OpenElectWidget(UUiElect* InElectWidget)
{
	ElectWidget = InElectWidget;
	Pin->AddChild(InElectWidget);
}

void UUiHudElect::ClearElect()
{
	ElectWidget->RemoveFromParent();
}