//Copyright 2015-2019, All Rights Reserved.

#include "Protocol/Writer/WriDataCreateP.h"
#include "Protocol/Writer/Ui/WriDataCreateU.h"



WriDataCreateP::WriDataCreateP(int InID, WriDataP* InPro) : ProtocolC(InID,this)
{
	Pro_ = InPro;
}

void WriDataCreateP::ConstructUi(UWriDataCreate* InView)
{
	View_ = InView;
	View_->UiConstruct(this);
}

bool WriDataCreateP::InputCommand(KeyS InKey)
{
	return FocalInputCommand(InKey);
}

void WriDataCreateP::FluxOpen_Technical(FluxSwitchOpC* InOp)
{
	View_->Show();

}

void WriDataCreateP::FluxClose_Technical(FluxSwitchOpC* InOp)
{
	View_->Hide();
}