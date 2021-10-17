// Fill out your copyright notice in the Description page of Project Settings.


#include "Pro/AppPro.h"
#include "Engine/StreamableManager.h"
#include "Engine/AssetManager.h"
#include "AppMode.h"
#include "AppMem.h"
#include "Pro/StoryPro.h"

namespace Global
{
	AAppPro* AppPro;
}

AAppPro::AAppPro()
{
	bReplicates = true;
}

AAppPro* AAppPro::GetAppPro(const UObject* WorldContextObject)
{
	return AAppMode::GetAppMode(WorldContextObject)->AppPro;
}

void AAppPro::GetAppProBP(AAppPro*& AppPro)
{
	AppPro = Global::AppPro;
}


void AAppPro::BeginPlay()
{
	Global::AppPro = this;
	Super::BeginPlay();	
}

void AAppPro::Init(AAppMem* InAppMem)
{
	AppMem = InAppMem;

	if (StoryProClass == NULL)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "StoryPro is not set in AppPro");
		return;
	}

	FStreamableManager& Streamable = UAssetManager::GetStreamableManager();
	Streamable.RequestAsyncLoad(StoryProClass.ToSoftObjectPath(), FStreamableDelegate::CreateUObject(this, &AAppPro::InitLL));
}

void AAppPro::InitLL()
{
	FVector Location(0.0f, 0.0f, 0.0f);
	FRotator Rotation(0.0f, 0.0f, 0.0f);
	FActorSpawnParameters SpawnInfo;
	SpawnInfo.bNoFail = true;
	StoryPro = GetWorld()->SpawnActor<AStoryPro>(StoryProClass.Get(), Location, Rotation, SpawnInfo);
	StoryPro->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
	StoryPro->OnInitComplete.AddDynamic(this, &AAppPro::InitSO);
	StoryPro->Init(this);

}


void AAppPro::InitSO()
{
	InitBP();
	Initialized = true;
	OnInitComplete.Broadcast();
}

void AAppPro::RouteBT(UInputButtonEvent* BT)
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "Route Key!");
}

void AAppPro::StartApp()
{
	DoStartAppBP();
}

void AAppPro::StartNewGame(FNewGameSettings NewGameSettings)
{
	DoStartNewGameBP();
}

void AAppPro::StartStoryBP(UStory* Story)
{
	AppMode = EAppMode::EAppModeStory;
	StoryPro->LoadStory(Story);
}