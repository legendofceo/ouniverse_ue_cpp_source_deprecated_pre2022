//Copyright 2015-2019, All Rights Reserved.

#include "Protocol/Writer/WriFileP.h"
#include "Protocol/Writer/Ui/WriFileU.h"
#include "Protocol/Writer/Ui/WriFileU_ScrollEntry.h"
#include "Protocol/Writer/WriPro.h"
#include "Protocol/Writer/Ex/WriLoadout.h"

#include "System/InputID.h"
#include "Ui/Ui.h"

#include "Ui/UiButton.h"
#include "Protocol/Focus.h"
#include "Interface/Array.h"


WriFileP::WriFileP(int InID, WriMenuP* InPro, WriterPro* InWriPro, WriLoadoutC* InWriData, AtlasLibC* InAtlasLib) : ProtocolC(InID,this)
{
	Pro_ = InPro;
	WriPro_ = InWriPro;

	AtlasLib_ = InAtlasLib;
	WriData_ = InWriData;

	FScroller_ = new FocusUiC(Focus::FRack, this);
	RegisterFocus(FScroller_);

	FRack_ = new FocusUiRackC(Focus::FRack, this, true, false);
	RegisterFocus(FRack_);
}

void WriFileP::ConstructUi(UWriFile* InView)
{
	View_ = InView;
	View_->UiConstruct(this,AtlasLib_);
}

bool WriFileP::InputCommand(KeyS InKey)
{
	return FocalInputCommand(InKey);
}

void WriFileP::FluxOpen_Technical(FluxSwitchOpC* InOp)
{
	View_->Show();	
	View_->OpenUi();
	View_->UiOpenBP();
}

void WriFileP::FluxClose_Technical(FluxSwitchOpC* InOp)
{
	View_->Hide();
}

void WriFileP::AcceptLoad()
{
	WriData_->Dismount();
	View_->SetData(WriData_);
	WriPro_->GoDataLoad();
}

void WriFileP::AcceptNew()
{

}