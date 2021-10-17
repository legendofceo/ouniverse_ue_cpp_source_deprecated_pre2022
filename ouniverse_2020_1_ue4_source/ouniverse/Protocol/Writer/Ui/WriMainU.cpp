//Copyright 2015-2019, All Rights Reserved.

#include "Protocol/Writer/Ui/WriMainU.h"
#include "Protocol/Writer/WriMainP.h"
#include "Protocol/Writer/WriGlobal.h"
#include "Ui/UiButton.h"
#include "Ui/UiEventCodes.h"

void UWriMenu::NativeConstruct()
{
	Super::NativeConstruct();

	vLoadout->SetupButton(REG::RLoadout, this);
	vLoadout->SetText(WriGlobalC::Dict(86665931));

	vAtlas->SetupButton(REG::RAtlas, this);
	vAtlas->SetText(WriGlobalC::Dict(1539337606));

	vData->SetupButton(REG::RData, this);
	vData->SetText(WriGlobalC::Dict(1872351585));

	vWorld->SetupButton(REG::RWorld, this);
	vWorld->SetText(WriGlobalC::Dict(1234621014));

	vTools->SetupButton(REG::RTools, this);
	vTools->SetText(WriGlobalC::Dict(867510666));

	vExit->SetupButton(REG::RExit, this);
	vExit->SetText(WriGlobalC::Dict(28132344));

	DataUnload();

}

void UWriMenu::UiConstruct(WriMenuP* InPro)
{
	Pro_ = InPro;
}

void UWriMenu::EventUi(int WidgetID, int InEventID, UUserWidget* InWidget)
{
	if (InEventID == UiEventsC::ButtonAccept || InEventID == UiEventsC::MouseLeftClick)
	{
		switch (WidgetID) {
		case REG::RLoadout:
			Pro_->AcceptLoadout();
			break;
		case REG::RAtlas:
			Pro_->AcceptAtlas();
			break;
		case REG::RData:
			Pro_->AcceptForm();
			break;
		}

	}
}

void UWriMenu::DataLoad()
{
	vAtlas->ButtonUnlock();
	vData->ButtonUnlock();
	vWorld->ButtonUnlock();
	vTools->ButtonUnlock();
}

void UWriMenu::DataUnload()
{
	vAtlas->ButtonLock();
	vData->ButtonLock();
	vWorld->ButtonLock();
	vTools->ButtonLock();
}