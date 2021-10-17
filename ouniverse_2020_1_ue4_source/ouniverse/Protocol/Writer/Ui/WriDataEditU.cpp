//Copyright 2015-2019, All Rights Reserved.

#include "Protocol/Writer/Ui/WriDataEditU.h"
#include "Ui/UiButton.h"

#include "System/FormData.h"
#include "System/Atlas.h"

#include "Data/DataD.h"

#include "Ui/UiPoly.h"

#include "Components/TextBlock.h"
#include "Components/MultiLineEditableTextBox.h"
#include "Interface/Json.h"

void UWriDataEdit::NativeConstruct()
{
	Super::NativeConstruct();

	vDataMode->SetupButton(REG::RDataMode,this);
	vOutputMode->SetupButton(REG::ROutputMode, this);
	vSave->SetupButton(REG::RSave, this);

}

void UWriDataEdit::NativeDestruct()
{

	Super::NativeDestruct();
}

void UWriDataEdit::UiConstruct(WriDataEditP* InPro)
{
	Pro_ = InPro;
}


void UWriDataEdit::OpenForm(FormDataC* InFormData)
{
	vPoly->View(InFormData->Form()->Poly());

	vUID->SetText(StringC(InFormData->Form()->UID().ToInt()).ToFText());
	vAUID->SetText(StringC(InFormData->Atlas()->UID().ForUI()).ToFText());
}