// Fill out your copyright notice in the Description page of Project Settings.


#include "StoryLib.h"
#include "Story.h"


namespace Lib
{
	UStoryLib* Story = NULL;
}

UStoryLib* UStoryLib::Get()
{
	return Lib::Story;
}

void UStoryLib::GetStoryLibBP(UStoryLib*& StoryLib)
{
	StoryLib = Lib::Story;
}

void UStoryLib::Init()
{
	Lib::Story = this;
	Stories.Empty();
	ULib::Init();
}

void UStoryLib::PostSS()
{
	Log.W("InitPostAsync()").UE();
	PostSSBP();
	Complete();
}

void UStoryLib::PostInit()
{
	Log.W("Calling Init on all Stories.").UE();

	for (const TPair<int, UStory* >& Pair : Stories)
	{
		Pair.Value->Init();
	}

	Complete();
}

void UStoryLib::StorySCP(TSoftClassPtr<UStory>SCP, TSoftClassPtr<UStory>& R)
{
	R = SCP;
}

void UStoryLib::RegStory(TSoftClassPtr<UStory> StoryClass, FString MarshalKey, UStory*& Param)
{
	if (!StoryClass.IsValid())
	{
		Log.W("A StorySoftClass was invalid: " + MarshalKey).Type(TCRIT).DM().UE();
	}
	UStory* NewStory = NewObject<UStory>(this, StoryClass.Get());
	Log.W("RegisteringStory: " + FString::FromInt(NewStory->Key)).UE();
	Marshal.AddObject(MarshalKey, &NewStory->Marshal);
	Param = NewStory;
	Stories.Add(NewStory->Key, NewStory);
}