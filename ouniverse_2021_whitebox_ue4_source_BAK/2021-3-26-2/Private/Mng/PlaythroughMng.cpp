// Fill out your copyright notice in the Description page of Project Settings.


#include "Mng/PlaythroughMng.h"
#include "Mng/StoryMng.h"
#include "Playthrough.h"
#include "Story.h"

UPlaythroughMng::UPlaythroughMng()
{

	PrimaryComponentTick.bCanEverTick = false;

}



void UPlaythroughMng::BeginPlay()
{
	Super::BeginPlay();

}

void UPlaythroughMng::Init()
{

}

void UPlaythroughMng::InitII(APlaythrough* InPlaythrough,UStoryMng* InStoryMng)
{	
	Playthrough = InPlaythrough;
	StoryMng = InStoryMng;
}

void UPlaythroughMng::NewGame()
{
	/**
	AStory* FirstStory = Playthrough->GetStory(UStoryKeys::Primary);
	FirstStory->Obtain();
	Playthrough->SetActiveStory(FirstStory);
	NewGameBP();
	StoryMng->Start();
	*/
	//Crash here means mem was not created first.
	//AStory* StartStory = AppMem->GetStory(UStoryKeys::Primary);
	//StartStory->Obtain();
}