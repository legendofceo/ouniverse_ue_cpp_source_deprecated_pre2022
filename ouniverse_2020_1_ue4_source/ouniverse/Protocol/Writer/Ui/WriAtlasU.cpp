//Copyright 2015-2019, All Rights Reserved.

#include "Protocol/Writer/Ui/WriAtlasU.h"
#include "Protocol/Writer/WriAtlasP.h"
#include "Protocol/Writer/WriGlobal.h"
#include "Protocol/Writer/Ui/WriFieldU.h"
#include "Ui/UiEventCodes.h"

#include "Components/TextBlock.h"

#include "System/Atlas.h"
#include "System/AtlasUID.h"

void UWriAtlas::NativeConstruct()
{
	Super::NativeConstruct();

	
	vDscUID->SetText(WriGlobalC::Dict(2085060505));

	vID->SetupEditText(REG::RID,this);
	vID->SetupWriField(WriGlobalC::Dict(640757654),0);

	vTitle->SetupEditText(REG::RTitle, this);
	vTitle->SetupWriField(WriGlobalC::Dict(768874735), 0);

	vDesc->SetupEditText(REG::RDesc, this);
	vDesc->SetupWriField(WriGlobalC::Dict(1981955833), 0);

	vAuthor->SetupEditText(REG::RAuthor, this);
	vAuthor->SetupWriField(WriGlobalC::Dict(1348426006), 0);

	vWebsite->SetupEditText(REG::RWebsite, this);
	vWebsite->SetupWriField(WriGlobalC::Dict(1434030309), 0);
}

void UWriAtlas::UiConstruct(WriAtlasP* InPro)
{
	Pro_ = InPro;
}

void UWriAtlas::OpenUI(AtlasC* InAtlas)
{
	vUID->SetText(StringC(InAtlas->UID().ForUI()).ToFText());
	vID->SetText(InAtlas->ID().ToFText());
	vTitle->SetText(InAtlas->Name().ToFText());
	vDesc->SetText(InAtlas->Desc().ToFText());
	vAuthor->SetText(InAtlas->Author().ToFText());
	vWebsite->SetText(InAtlas->Website().ToFText());

}