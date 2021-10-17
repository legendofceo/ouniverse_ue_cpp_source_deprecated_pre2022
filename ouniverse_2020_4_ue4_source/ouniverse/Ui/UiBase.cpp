// Fill out your copyright notice in the Description page of Project Settings.

#include "UiBase.h"



void UUiBase::Hide()
{
	SetVisibility(ESlateVisibility::Collapsed);
}

void UUiBase::Show()
{
	SetVisibility(ESlateVisibility::SelfHitTestInvisible);
}
