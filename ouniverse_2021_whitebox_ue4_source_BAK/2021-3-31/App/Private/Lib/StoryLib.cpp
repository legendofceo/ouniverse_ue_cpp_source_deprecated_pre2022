// Fill out your copyright notice in the Description page of Project Settings.


#include "Lib/StoryLib.h"
#include "Story.h"
#include "PartyHandle.h"

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
	ULib::Init();
}

void UStoryLib::PostAsync()
{
	Log.Write(AAUTH, LNORM, VNONE, 1, 0, "InitPostAsync()");
	PostAsyncBP();

	Log.Write(AAUTH, LNORM, VNONE, 1, 0, "Calling Init on all Stories.");

	TMap<int, UStory*> exampleIntegerToActorMap;
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