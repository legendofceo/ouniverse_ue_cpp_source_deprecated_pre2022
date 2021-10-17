//Copyright 2015-2019, All Rights Reserved.

#include "Protocol/Writer/Ui/WriDataU_ScrollEntry.h"
#include "System/Scope.h"
#include "Class/ClassProtocol.h"

#include "Protocol/Writer/WriDataP.h"

#include "System/Atlas.h"
#include "Ui/UiMouseInput.h"

#include "Components/TextBlock.h"

#include "System/FormData.h"

void UWriData_ScrollEntry::NativeConstruct()
{
	Super::NativeConstruct();
	vTitle->SetText(FText::FromString(FormData_->Form()->ID().ToChar()));

	vOpen->Setup(REG::MiOpen, this);
	vSelect->Setup(REG::MiSelect, this);
}

UWriData_ScrollEntry* UWriData_ScrollEntry::Create(WriDataP* InDataPro, FormDataC* InFormData)
{
	UWriData_ScrollEntry* Neu = CreateWidget<UWriData_ScrollEntry>(ScopeC::World(), UClassProtocol::Get()->WriForm_ScrollEntryUI);
	Neu->Init(InDataPro, InFormData);
	return Neu;
}

void UWriData_ScrollEntry::Init(WriDataP* InDataPro, FormDataC* InFormData)
{
	DataPro_ = InDataPro;
	FormData_ = InFormData;
}

void UWriData_ScrollEntry::EventUi(int WidgetID, int InEventID, UUserWidget* InWidget)
{
	switch (WidgetID) {
	case REG::MiOpen:
		DataPro_->OpenData(FormData_);
		break;
	case REG::MiSelect:
		BoolSelectedToggle();
		break;
	}
}

void UWriData_ScrollEntry::BoolSelectedToggle()
{
	if (bSelected_)
	{
		bSelected_ = false;
		BoolSelectedOff();
	}
	else
	{
		bSelected_ = true;
		BoolSelectedOn();
	}
}