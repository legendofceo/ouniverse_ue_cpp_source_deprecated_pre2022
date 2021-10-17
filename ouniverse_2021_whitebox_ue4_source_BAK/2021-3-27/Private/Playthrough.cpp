// Fill out your copyright notice in the Description page of Project Settings.


#include "Playthrough.h"
#include "Story.h"

APlaythrough::APlaythrough()
{
	PrimaryActorTick.bCanEverTick = false;
}

AStory* APlaythrough::GetActiveStory()
{
	return ActiveStory;
}

void APlaythrough::SetActiveStory(AStory* Story)
{
	ActiveStory = Story;
}

void APlaythrough::SetActiveStoryBP(AStory* Story, AStory*& StoryR)
{
	StoryR = Story;
	SetActiveStory(Story);
}