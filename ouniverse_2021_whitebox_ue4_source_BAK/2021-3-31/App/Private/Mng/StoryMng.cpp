// Fill out your copyright notice in the Description page of Project Settings.


#include "Mng/StoryMng.h"
#include "Engine/StreamableManager.h"
#include "Engine/AssetManager.h"
#include "Story.h"
#include "PartyHandle.h"

namespace Manager
{
	AStoryMng* Story = NULL;
}

AStoryMng::AStoryMng() : AManagerActor(){}

AStoryMng* AStoryMng::Get()
{
	return Manager::Story;
}

void AStoryMng::GetStoryMngBP(AStoryMng*& StoryMng)
{
	StoryMng = Manager::Story;
}

void AStoryMng::BeginPlay()
{
	Manager::Story = this;
	Log.Write(AAUTH,LNORM,VNONE,1,0, "Init()");
	bInit = true;
	OnInitComplete.Broadcast(this);
		
}




void AStoryMng::StartStory(UStory* InStory)
{
	ActiveStory = InStory;
	Log.Write(AAUTH, LNORM, VNONE, 1, 0, "Story has been started: " + FString::FromInt(ActiveStory->Key));

	ActiveStory->PreStartBP();
	ActivePartyHandle = NewObject<UPartyHandle>(this, UPartyHandle::StaticClass());
	ActivePartyHandle->Load(&ActiveStory->Party);
	ActivePartyHandle->OnLoadComplete.AddDynamic(this, &AStoryMng::StartStoryLoadPartyComplete);
}

void AStoryMng::StartStoryLoadPartyComplete()
{
	Log.Write(AAUTH, LNORM, VNONE, 1, 0, "Loading Party Complete.");
}


void AStoryMng::AddCompanionToParty(UStory* Story, UCompanion* Companion)
{
	FParty* Party = &Story->Party;
	Party->AddCompanion(Companion);
}