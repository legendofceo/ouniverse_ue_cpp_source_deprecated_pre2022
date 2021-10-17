// Fill out your copyright notice in the Description page of Project Settings.

#include "TitleNewGamePro.h"
#include "AppWorld.h"
#include "Log.h"

const FName UTitleNewGamePro::SYS = "TitleNewGamePro";

void UTitleNewGamePro::Run()
{
	if (!TitleNewGameOptionsUiClass)
	{
		LOG.S(SYS).T(TCRIT).W("TitleNewGameOptionsUiClass is null").DebugM();
	}

	NewGameOptions = CreateWidget<UTitleNewGameOptionsUi>(UAppWorld::GetAppWorld(), TitleNewGameOptionsUiClass.Get());
	NewGameOptions->AddToViewport(500);

}