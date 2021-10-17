//Copyright 2015-2019, All Rights Reserved.

#include "Protocol/Writer/WriDataEditP.h"
#include "Protocol/Writer/Ui/WriDataU.h"
#include "Protocol/Writer/WriPro.h"

#include "System/InputID.h"

#include "Ui/Ui.h"

#include "Ui/UiButton.h"
#include "Protocol/Focus.h"

WriDataEditP::WriDataEditP(int InID, WriDataP* InPro) : ProtocolC(InID,this)
{
	Pro_ = InPro;
}

void WriDataEditP::ConstructUi(UWriDataEdit* InView)
{
	View_ = InView;
	View_->UiConstruct(this);
}

bool WriDataEditP::InputCommand(KeyS InKey)
{
	return FocalInputCommand(InKey);
}

void WriDataEditP::FluxOpen_Technical(FluxSwitchOpC* InOp)
{
	View_->Show();

}

void WriDataEditP::FluxClose_Technical(FluxSwitchOpC* InOp)
{
	View_->Hide();
}

void WriDataEditP::OpenData(FormDataC* InFormData)
{
	View_->OpenForm(InFormData);
}