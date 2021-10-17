//Copyright 2015-2019, All Rights Reserved.

#include "Protocol/Writer/Ui/WriFileU_ScrollEntry.h"
#include "System/Scope.h"
#include "Class/ClassProtocol.h"
#include "Protocol/Writer/Ui/WriFileU.h"

#include "System/Atlas.h"
#include "Ui/UiMouseInput.h"

#include "Components/TextBlock.h"

void UWriFile_ScrollEntry::NativeConstruct()
{
	Super::NativeConstruct();
	vTitle->SetText(FText::FromString(Atlas_->ID().ToChar()));

	vMiMaster->Setup(REG::BoolMaster, this);
	vMiSupport->Setup(REG::BoolActive, this);
}

UWriFile_ScrollEntry* UWriFile_ScrollEntry::Create(UWriFile* InView, AtlasC* InAtlas)
{
	UWriFile_ScrollEntry* Neu = CreateWidget<UWriFile_ScrollEntry>(ScopeC::World(), UClassProtocol::Get()->WriLoadout_ScrollEntryUI);
	Neu->Init(InView, InAtlas);
	return Neu;
}

void UWriFile_ScrollEntry::Init(UWriFile* InView, AtlasC* InAtlas)
{
	Atlas_ = InAtlas;
	View_ = InView;
}

void UWriFile_ScrollEntry::EventUi(int WidgetID, int InEventID, UUserWidget* InWidget)
{
	switch (WidgetID) {
	case REG::BoolMaster:
		BoolMasterToggle(false);
		break;
	case REG::BoolActive:
		BoolActiveToggle();
		break;
	}
}

void UWriFile_ScrollEntry::BoolMasterToggle(bool FromView)
{
	if (AtlasMaster_)
	{
		AtlasMaster_ = false;
		BoolMasterOff();
		if (!FromView)
		{
			View_->MasterCleared();
		}
	}
	else
	{
		AtlasMaster_ = true;
		BoolMasterOn();
		if (!FromView)
		{
			View_->MasterSet(this);
		}
	}
}

void UWriFile_ScrollEntry::BoolActiveToggle()
{
	if (AtlasActive_)
	{
		AtlasActive_ = false;
		BoolActiveOff();
	}
	else
	{
		AtlasActive_ = true;
		BoolActiveOn();
	}
}