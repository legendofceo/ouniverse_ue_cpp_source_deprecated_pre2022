// Fill out your copyright notice in the Description page of Project Settings.


#include "OnwardMenuPro.h"
#include "Engine/StreamableManager.h"
#include "Engine/AssetManager.h"
#include "Log.h"
#include "AppWorld.h"

const FName UOnwardMenuPro::SYS = "OnwardMenuPro";

namespace Pro
{
	UOnwardMenuPro* MainMenu = nullptr;
}

UOnwardMenuPro::UOnwardMenuPro() : UProtocol()
{

}

UOnwardMenuPro* UOnwardMenuPro::Get()
{
	return Pro::MainMenu;
}

void UOnwardMenuPro::GetBP(UOnwardMenuPro*& OnwardMenuPro)
{
	OnwardMenuPro = Pro::MainMenu;
}

void UOnwardMenuPro::Init()
{
	Pro::MainMenu = this;
	LOG.S(SYS).W("Init Complete()");
	InitComplete();
}


void UOnwardMenuPro::Engage()
{
	LOG.S(SYS).W("Engage()");
	EngageBP();
}




void UOnwardMenuSubmenu::Init(UOnwardMenuPro* InPro, UOnwardMenuSubmenu* InParent)
{
	Pro = InPro;
	Parent = InParent;
}