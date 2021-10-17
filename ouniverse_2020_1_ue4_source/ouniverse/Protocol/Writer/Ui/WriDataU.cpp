//Copyright 2015-2019, All Rights Reserved.

#include "Protocol/Writer/Ui/WriDataU.h"
#include "Protocol/Writer/WriDataP.h"

#include "Protocol/Writer/Ui/WriDataEditU.h"


void UWriData::NativeConstruct()
{
	Super::NativeConstruct();
}

void UWriData::NativeDestruct()
{
	Super::NativeDestruct();
}

void UWriData::UiConstruct(WriDataP* InPro, AtlasLibC* InAtlasLib)
{
	Pro_ = InPro;
	AtlasLib_ = InAtlasLib;
}