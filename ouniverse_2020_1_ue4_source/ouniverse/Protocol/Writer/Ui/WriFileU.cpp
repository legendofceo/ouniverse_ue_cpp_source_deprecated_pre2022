//Copyright 2015-2019, All Rights Reserved.

#include "Protocol/Writer/Ui/WriFileU.h"
#include "Protocol/Writer/Ui/WriFileU_ScrollEntry.h"
#include "Protocol/Writer/WriFileP.h"

#include "Protocol/Writer/WriGlobal.h"

#include "Protocol/Writer/Ex/WriLoadout.h"
#include "Interface/Array.h"

#include "System/AtlasLib.h"

#include "Components/TextBlock.h"
#include "Ui/UiScroll.h"
#include "Ui/UiButton.h"
#include "Ui/UiEventCodes.h"


void UWriFile::NativeConstruct()
{
	MasterEntry_ = NULL;
	Super::NativeConstruct();
	
	vDscStatus->SetText(WriGlobalC::Dict(715882028));

	vSave->SetupButton(REG::RSave, this);
	vSave->SetText(WriGlobalC::Dict(146155872));

	vLoad->SetupButton(REG::RLoad, this);
	vLoad->SetText(WriGlobalC::Dict(1351590169));

	vUnload->SetupButton(REG::RUnload, this);
	vUnload->SetText(WriGlobalC::Dict(1153121336));

	vNew->SetupButton(REG::RNew, this);
	vNew->SetText(WriGlobalC::Dict(395410456));

	vDelete->SetupButton(REG::RDelete, this);
	vDelete->SetText(WriGlobalC::Dict(1683981082));


	FirstDraw_ = false;
}

void UWriFile::UiConstruct(WriFileP* InPro, AtlasLibC* InAtlasLib)
{
	Pro_ = InPro;
	AtlasLib_ = InAtlasLib;
}

void UWriFile::OpenUi()
{

	if (!FirstDraw_)
	{
		UnloadedMode();

		vScroll->ClearChildren();

		int L = AtlasLib_->GetAtlasPreMap()->Len();

		for (int i = 0; i < L; i++)
		{
			UWriFile_ScrollEntry* Entry = UWriFile_ScrollEntry::Create(this, AtlasLib_->GetAtlasPreMap()->At(i));
			vScroll->AddEntry(Entry);
		}

		FirstDraw_ = true;
	}


}

void UWriFile::MasterSet(UWriFile_ScrollEntry* InMaster)
{
	if (MasterEntry_ != NULL)
	{
		MasterEntry_->BoolMasterToggle(true);
	}

	MasterEntry_ = InMaster;
}

void UWriFile::MasterCleared()
{
	MasterEntry_ = NULL;
}

void UWriFile::EventUi(int WidgetID, int InEventID, UUserWidget* InWidget)
{
	if (InEventID == UiEventsC::ButtonAccept || InEventID == UiEventsC::MouseLeftClick)
	{
		switch (WidgetID) {
		case REG::RLoad:
			Pro_->AcceptLoad();
			break;
		case REG::RNew:
			Pro_->AcceptNew();
			break;
		}
	}
}

void UWriFile::SetData(WriLoadoutC* InData)
{
	int L = vScroll->Entries_.Len();
	UWriFile_ScrollEntry* Cur;

	for (int i = 0; i < L; i++)
	{
		Cur = static_cast<UWriFile_ScrollEntry*>(vScroll->Entries_[i]);
		
		if (Cur->AtlasMaster_)
		{
			InData->Loadout_.Add(Cur->Atlas_);
			InData->SetMaster(Cur->Atlas_);
		}
		else if (Cur->AtlasActive_)
		{
			InData->Loadout_.Add(Cur->Atlas_);
		}
	}

	LoadedMode();
}


void UWriFile::UnloadedMode()
{
	vLoad->SetVisibility(ESlateVisibility::Visible);
	vUnload->SetVisibility(ESlateVisibility::Collapsed);
	vSave->SetVisibility(ESlateVisibility::Collapsed);
	vNew->SetVisibility(ESlateVisibility::Visible);
	vDelete->SetVisibility(ESlateVisibility::Visible);

	vStatus->SetText(WriGlobalC::Dict(1537626057));
}

void UWriFile::LoadedMode()
{
	vLoad->SetVisibility(ESlateVisibility::Collapsed);
	vUnload->SetVisibility(ESlateVisibility::Visible);
	vSave->SetVisibility(ESlateVisibility::Visible);
	vNew->SetVisibility(ESlateVisibility::Collapsed);
	vDelete->SetVisibility(ESlateVisibility::Collapsed);

	vStatus->SetText(WriGlobalC::Dict(344589223));
}