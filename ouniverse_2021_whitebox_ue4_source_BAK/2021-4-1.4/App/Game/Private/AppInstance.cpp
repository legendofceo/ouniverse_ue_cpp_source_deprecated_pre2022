// Fill out your copyright notice in the Description page of Project Settings.


#include "AppInstance.h"
#include "GameData.h"

namespace Global
{
	UApp* AppInstance;
}


void UApp::Init()
{
	Global::AppInstance = this;
}

void UApp::GetApp(UApp*& App)
{
	App = Global::AppInstance; 
}

void UApp::Boot()
{
	GameData = NewObject<UGameData>(this, UGameData::StaticClass());
	GameData->Init();
}