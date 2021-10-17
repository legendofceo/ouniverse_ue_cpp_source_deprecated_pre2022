// Fill out your copyright notice in the Description page of Project Settings.


#include "Playthrough.h"
#include "Story.h"


namespace GameData
{
	UPlaythrough* Playthrough;
}


UPlaythrough* UPlaythrough::Get()
{
	return GameData::Playthrough;
}

UPlaythrough::UPlaythrough()
{

}

UStory* UPlaythrough::GetActiveStory()
{
	return ActiveStory;
}

void UPlaythrough::SetActiveStory(UStory* InStory)
{
	ActiveStory = InStory;
}

void UPlaythrough::Init()
{
	GameData::Playthrough = this;
	InitBP();
	OnInitComplete.Broadcast(this);
}

void UPlaythrough::InitPostLib()
{
	InitPostLibBP();
	OnInitComplete.Broadcast(this);
}