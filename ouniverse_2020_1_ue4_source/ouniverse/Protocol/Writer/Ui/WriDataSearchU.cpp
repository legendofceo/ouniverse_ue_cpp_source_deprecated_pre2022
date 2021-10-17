//Copyright 2015-2019, All Rights Reserved.

#include "Protocol/Writer/Ui/WriDataSearchU.h"
#include "Ui/UiButton.h"
#include "Protocol/Writer/WriGlobal.h"

#include "Protocol/Writer/Ui/WriDataU_ScrollEntry.h"

#include "Protocol/Writer/WriGlobal.h"
#include "Components/TextBlock.h"
#include "Components/EditableText.h"

#include "System/AtlasLib.h"

#include "Interface/String.h"
#include "System/FormQuery.h"

#include "Interface/String.h"
#include "Ui/UiScroll.h"

void UWriDataSearch::NativeConstruct()
{
	Super::NativeConstruct();

	vDscFilters->SetText(WriGlobalC::Dict(594783876));
	vDscOptions->SetText(WriGlobalC::Dict(2012185030));

	vData->SetupButton(REG::RData, this);
	vData->SetText(WriGlobalC::Dict(1872351585));

	vRevision->SetupButton(REG::RRevision, this);
	vRevision->SetText(WriGlobalC::Dict(1446889365));

	vAmmend->SetupButton(REG::RAmmend, this);
	vAmmend->SetText(WriGlobalC::Dict(930130512));

	vNew->SetupButton(REG::RNew, this);
	vNew->SetText(WriGlobalC::Dict(395410456));

	vDelete->SetupButton(REG::RDelete , this);
	vDelete->SetText(WriGlobalC::Dict(1683981082));

	vSearch->SetupButton(REG::RSearch, this);
	vSearch->SetText(WriGlobalC::Dict(2130583320));

	vDscView->SetText(WriGlobalC::Dict(1914866211));

	vView0->SetupButton(REG::RView0, this);
	vView0->SetText(StringC("1").ToFText());

	vView1->SetupButton(REG::RView1, this);
	vView1->SetText(StringC("2").ToFText());

	vView2->SetupButton(REG::RView2, this);
	vView2->SetText(StringC("3").ToFText());

	vMaster->SetupButton(REG::RMaster, this);
	vMaster->SetText(WriGlobalC::Dict(195511168));

	vSupport->SetupButton(REG::RSupport, this);
	vSupport->SetText(WriGlobalC::Dict(1561326530));

	vJson->SetupButton(REG::RJson, this);
	vJson->SetText(WriGlobalC::Dict(1058280362));

	vQuery->OnTextCommitted.AddDynamic(this, &UWriDataSearch::OnTextCommitted);
}

void UWriDataSearch::NativeDestruct()
{
	vQuery->OnTextCommitted.RemoveDynamic(this, &UWriDataSearch::OnTextCommitted);
	Super::NativeDestruct();
}

void UWriDataSearch::UiConstruct(WriDataSearchP* InPro, WriDataP* InDataPro, AtlasLibC* InAtlasLib)
{
	Pro_ = InPro;
	DataPro_ = InDataPro;
	AtlasLib_ = InAtlasLib;
}

void UWriDataSearch::OnTextCommitted(const FText& Text, ETextCommit::Type CommitMethod)
{
	switch (CommitMethod) {
	case ETextCommit::Type::OnEnter:
		Query();
		break;
	case ETextCommit::Type::OnUserMovedFocus:
		// code block
		break;
	}
}

void UWriDataSearch::Query()
{

	StringC QueryText = vQuery->GetText();

	FormRefs_.Clear();
	vScroll->ClearChildren();

	FormDataQueryC* FormQuery = new FormDataQueryC(QueryText, &FormRefs_);
	AtlasLib_->QueryFormData(FormQuery);

	int L = FormRefs_.Len();
	for (int i = 0; i < L; i++)
	{
		UWriData_ScrollEntry* Entry = UWriData_ScrollEntry::Create(DataPro_, FormRefs_[i]);
		vScroll->AddEntry(Entry);
	}

	delete FormQuery;
}