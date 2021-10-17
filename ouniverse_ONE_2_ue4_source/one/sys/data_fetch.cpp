// Fill out your copyright notice in the Description page of Project Settings.

#include "data_fetch.h"
#include "data_manager.h"
#include "atlas.h"

AtlasFetchS::AtlasFetchS(int InPackUN)
{
	UDataManager* DataManager = UDataManager::Get();
	if (DataManager->TryAtlas(Atlas_, InPackUN))
	{
		if (GEngine) { GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, Atlas()->StringUID); }
		bSuccess = true;
	}
}

UAtlas* AtlasFetchS::Atlas()
{
	return Atlas_;
}

bool AtlasFetchS::Success()
{
	return bSuccess;
}

FetchDataS::FetchDataS(FDataAddress InAddress)
{
	AtlasFetch = AtlasFetchS(InAddress.Pack());


	if (AtlasFetch.Success())
	{
		if (AtlasFetch.Atlas()->TryData(Form, InAddress.Form()))
		{
			bSuccess = true;
		}
	}

}