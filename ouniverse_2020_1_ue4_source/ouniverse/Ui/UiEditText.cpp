//Copyright 2015-2019, All Rights Reserved.

#include "Ui/UiEditText.h"
#include "Components/EditableText.h"

void UUiEditText::NativeConstruct()
{
	Super::NativeConstruct();
}

void UUiEditText::Require(UEditableText* InText)
{
	vText = InText;
}

void UUiEditText::SetupEditText(int InID, UUiBase* InRelay)
{
	ID_ = InID;
	Relay_ = InRelay;
}

void UUiEditText::SetText(FText InText)
{
	vText->SetText(InText);
}