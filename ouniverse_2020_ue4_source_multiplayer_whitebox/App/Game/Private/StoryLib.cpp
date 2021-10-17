// Fill out your copyright notice in the Description page of Project Settings.


#include "StoryLib.h"
#include "Log.h"
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
	LOG.S(SYS).W("InitPostAsync()");
	PostSSBP();
	Complete();
}

void UStoryLib::PostInit()
{
	LOG.S(SYS).W("Calling Init on all Stories.");

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
		LOG.S(SYS).T(TCRIT).W("A StorySoftClass was invalid: " + MarshalKey).DebugM();
	}
	UStory* NewStory = NewObject<UStory>(this, StoryClass.Get());
	LOG.S(SYS).W("RegisteringStory: " + FString::FromInt(NewStory->Key));
	Marshal.AddObject(MarshalKey, &NewStory->Marshal);
	Param = NewStory;
	Stories.Add(NewStory->Key, NewStory);
}