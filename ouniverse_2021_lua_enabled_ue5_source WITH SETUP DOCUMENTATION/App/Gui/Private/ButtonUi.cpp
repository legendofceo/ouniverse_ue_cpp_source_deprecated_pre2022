// Fill out your copyright notice in the Description page of Project Settings.


#include "ButtonUi.h"
#include "AppController.h"

FReply UButtonUi::NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InButtonEvent)
{
	if (AAppController::Get()->IsPeripheralModeMouse() && AAppController::Get()->bMouseMode)
	{
		FKey Key = InButtonEvent.GetEffectingButton();

		if (Key == FKey(EKeys::LeftMouseButton))
		{

			OnButtonEvent.ExecuteIfBound(EButtonEvents::LeftDown);

		}
		else if (Key == FKey(EKeys::RightMouseButton))
		{

			OnButtonEvent.ExecuteIfBound(EButtonEvents::RightDown);

		}

		return FReply::Handled();
	}

	return FReply::Unhandled();
}

FReply UButtonUi::NativeOnMouseButtonUp(const FGeometry& InGeometry, const FPointerEvent& InButtonEvent)
{

	if (AAppController::Get()->IsPeripheralModeMouse() && AAppController::Get()->bMouseMode)
	{
		FKey Key = InButtonEvent.GetEffectingButton();

		if (Key == FKey(EKeys::LeftMouseButton))
		{

			OnButtonEvent.ExecuteIfBound(EButtonEvents::LeftUp);
			OnButtonEvent.ExecuteIfBound(EButtonEvents::LeftClick);
		}
		else if (Key == FKey(EKeys::RightMouseButton))
		{

			OnButtonEvent.ExecuteIfBound(EButtonEvents::RightUp);
			OnButtonEvent.ExecuteIfBound(EButtonEvents::RightClick);
		}

		return FReply::Handled();
	}


	return FReply::Unhandled();
}

void UButtonUi::NativeOnMouseEnter(const FGeometry& InGeometry, const FPointerEvent& InButtonEvent)
{
	if (AAppController::Get()->IsPeripheralModeMouse() && AAppController::Get()->bMouseMode)
	{
		OnButtonEvent.ExecuteIfBound(EButtonEvents::Hover);
	}
}

void UButtonUi::NativeOnMouseLeave(const FPointerEvent& InButtonEvent)
{
	if (AAppController::Get()->IsPeripheralModeMouse() && AAppController::Get()->bMouseMode)
	{
		OnButtonEvent.ExecuteIfBound(EButtonEvents::Unhover);
	}
}

void UButtonUi::Subscribe(const FDelDynamicButtonEvent& Event)
{
	OnButtonEvent = Event;
}