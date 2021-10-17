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
	Log.Write(AAUTH, LNORM, VNONE, 1, 0, "InitPostAsync()");
	PostSSBP();
	Complete();
}

void UStoryLib::PostInit()
{
	Log.Write(AAUTH, LNORM, VNONE, 1, 0, "Calling Init on all Stories.");

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
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "A StorySoftClass was invalid: " + MarshalKey);
		Log.Write(AAUTH, LCRIT, VNONE, 1, 0, "A StorySoftClass was invalid: " + MarshalKey);
	}
	UStory* NewStory = NewObject<UStory>(this, StoryClass.Get());
	Log.Write(AAUTH, LNORM, VNONE, 1, 0, "RegisteringStory: " + FString::FromInt(NewStory->Key));
	Marshal.AddObject(MarshalKey, &NewStory->Marshal);
	Param = NewStory;
	Stories.Add(NewStory->Key, NewStory);
}