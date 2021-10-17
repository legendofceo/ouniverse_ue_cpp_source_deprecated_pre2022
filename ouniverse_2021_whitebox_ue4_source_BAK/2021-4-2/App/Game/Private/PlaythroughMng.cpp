// Fill out your copyright notice in the Description page of Project Settings.


#include "PlaythroughMng.h"
#include "StoryMng.h"

namespace Manager
{
	APlaythroughMng* Playthrough = NULL;
}

APlaythroughMng::APlaythroughMng() : ANexus() {}

void APlaythroughMng::BeginPlay()
{
	Super::BeginPlay();
	Manager::Playthrough = this;
	Log.Write(AAUTH, LNORM, VNONE, 1, 0, "Init()");
	bInit = true;
	OnInitComplete.Broadcast(this);

}

void APlaythroughMng::SetActiveStory(UStory* InStory)
{
	ActiveStory = InStory;
}

void APlaythroughMng::NewGame()
{
	NewGameBP();
}

void APlaythroughMng::StartGame()
{
	StartGameBP();

	if (ActiveStory == NULL)
	{
		Log.Write(AAUTH, LCRIT, VNONE, 1, 0, "No Active Story was set when StartStory was called.");
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "No Active Story was set when StartStory was called.");
	}
	else
	{
		ACosmNexus* StoryMng = ACosmNexus::Get();
		StoryMng->StartStory(ActiveStory);
	}
}