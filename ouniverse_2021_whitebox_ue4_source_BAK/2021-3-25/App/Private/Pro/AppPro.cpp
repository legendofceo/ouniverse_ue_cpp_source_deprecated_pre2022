// Fill out your copyright notice in the Description page of Project Settings.


#include "Pro/AppPro.h"
#include "Engine/StreamableManager.h"
#include "Engine/AssetManager.h"
#include "AppMode.h"
#include "AppMem.h"
#include "Pro/StoryPro.h"


UAppPro::UAppPro()
{

}

void UAppPro::BT(UInputButtonEvent* BT)
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "I AM TRIGGERED");
	Test();
}

void UAppPro::BeginPlay()
{
	Super::BeginPlay();	
}

void UAppPro::Init(AAppMem* InAppMem)
{
	AppMem = InAppMem;
}

void UAppPro::RouteBT(UInputButtonEvent* BT)
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "Route Key!");
}

void UAppPro::StartApp()
{
	DoStartAppBP();
}

void UAppPro::StartNewGame(FNewGameSettings NewGameSettings)
{
	DoStartNewGameBP();
}

void UAppPro::StartStoryBP(UStory* Story)
{
	AppMode = EAppMode::EAppModeStory;
	StoryPro->LoadStory(Story);
}