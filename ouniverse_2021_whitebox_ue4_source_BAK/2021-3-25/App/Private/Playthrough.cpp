// Fill out your copyright notice in the Description page of Project Settings.


#include "Playthrough.h"

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
}