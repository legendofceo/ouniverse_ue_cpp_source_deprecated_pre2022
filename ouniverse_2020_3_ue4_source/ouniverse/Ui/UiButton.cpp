
//Copyright 2015-2019, All Rights Reserved.

#include "Ui/UiButton.h"
#include "Ui/UiEventCodes.h"

#include "Components/TextBlock.h"

void UUiButton::SetupButton(int InID, UUiBase* InRelay)
{
	bIsFocusable = true;
	bLocked = false;

	ID_ = InID;
	Relay_ = InRelay;
}

FReply UUiButton::NativeOnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	if (!bLocked)
	{
		bPressed = true;
		Relay_->EventUi(ID_, UiEventsC::MouseLeftDown, this);
		return FReply::Handled();
	}

	return FReply::Handled();
}

FReply UUiButton::NativeOnMouseButtonUp(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	if (!bLocked)
	{

		Relay_->EventUi(ID_, UiEventsC::MouseLeftUp, this);

		if (bPressed)
		{
			Relay_->EventUi(ID_, UiEventsC::MouseLeftClick, this);
		}

		bPressed = false;
		return FReply::Handled();
	}

	return FReply::Handled();
}

void UUiButton::NativeOnMouseEnter(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	if (!bLocked)
	{
		Relay_->EventUi(ID_, UiEventsC::MouseEnter, this);
		HoveredBP();

	}

}

void UUiButton::NativeOnMouseLeave(const FPointerEvent& MouseEvent)
{
	if (!bLocked)
	{
		Relay_->EventUi(ID_, UiEventsC::MouseExit, this);
		UnhoveredBP();

	}


}

bool UUiButton::OnStroke(const FFKey& InStroke)
{
	/**
	switch (InKey.Command) {
	case InputID::Up_D:
		Focus_->Call(LeyS::Dir::Up);
		return true;
	case InputID::Down_D:
		Focus_->Call(LeyS::Dir::Down);
		return true;
	case InputID::Accept_D:
		Relay_->EventUi(ID_, UiEventsC::ButtonAccept, this);;
		return true;
	case InputID::Left_D:
		Focus_->Call(LeyS::Dir::Left);
		return true;
	case InputID::Right_D:
		Focus_->Call(LeyS::Dir::Right);
		return true;
	}
	*/

	return false;
}

void UUiButton::SetText(FText InText)
{
	Text_->SetText(InText);
}

void UUiButton::Require(UTextBlock* InText)
{
	Text_ = InText;
}

void UUiButton::ButtonLock()
{
	bLocked = true;
	ButtonLockBP();
}

void UUiButton::ButtonUnlock()
{
	bLocked = false;
	ButtonUnlockBP();
}