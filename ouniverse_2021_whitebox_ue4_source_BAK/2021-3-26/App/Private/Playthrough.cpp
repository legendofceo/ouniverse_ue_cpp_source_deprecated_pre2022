// Fill out your copyright notice in the Description page of Project Settings.


#include "Playthrough.h"
#include "AppMem.h"
#include "Mem/PlaythroughMem.h"
#include "Story.h"

void UPlaythrough::SetMem(FPlaythroughMem* PlaythroughMem)
{
	Mem = PlaythroughMem;
}

UStory* UPlaythrough::GetActiveStory()
{
	return ActiveStory;
}

void UPlaythrough::SetActiveStory(UStory* Story)
{
	ActiveStory = Story;
	Mem->ActiveStory = Story->Key;
}

void UPlaythrough::SetActiveStoryBP(UStory* Story, UStory*& StoryR)
{
	StoryR = Story;
	SetActiveStory(Story);
}

void UPlaythrough::AddStory(UStory* Story)
{
	Stories.Add(Story->Key, Story);
}

UStory* UPlaythrough::GetStory(int StoryKey)
{
	return Stories.FindRef(StoryKey);
}


void UPlaythrough::GetStoryBP(int Key, UStory*& Story)
{
	Story = AAppMem::GetAppMem()->Playthrough->GetStory(Key);
}
