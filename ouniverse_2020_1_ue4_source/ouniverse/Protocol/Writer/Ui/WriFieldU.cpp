//Copyright 2015-2019, All Rights Reserved.

#include "Protocol/Writer/Ui/WriFieldU.h"
#include "Components/EditableText.h"
#include "Components/TextBlock.h"

void UWriField::NativeConstruct()
{
	Super::NativeConstruct();
}

void UWriField::NativeDestruct()
{
	Super::NativeDestruct();
}

void UWriField::RequireWriField(UTextBlock* InDesc)
{
	vDesc = InDesc;
}

void UWriField::SetupWriField(FText InText, int InHelpID)
{
	vDesc->SetText(InText);
	HelpID_ = InHelpID;
}