// Fill out your copyright notice in the Description page of Project Settings.


#include "Mng/StoryMng.h"
#include "Mng/AreaMng.h"
#include "Mng/PartyMng.h"
#include "Mem/Story.h"

#include "AreaOverride.h"
#include "Handle/PartyHandle.h"

#include "Blue.h"

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

#if UE_BUILD_DEVELOPMENT
	/**
	FBlueEnsureImplementation BEF = FBlueEnsureImplementation();
	BEF.Add("InitBP");
	BEF.Add("PreStartBP");
	BEF.Add("PostStartBP");
	BEF.Go(this, ID.ToString());
	*/
#endif

	Manager::Story = this;
	Log.Write(AAUTH,LNORM,VNONE,1,0, "Init()");
	bInit = true;
	OnInitComplete.Broadcast(this);
		
}




void AStoryMng::StartStory(UStory* InStory)
{
	ActiveStory = InStory;
	Log.Write(AAUTH, LNORM, VNONE, 1, 0, "Story has been started: " + FString::FromInt(ActiveStory->Key));
	ActiveStory->PreStart();
	APartyMng* PartyMng = APartyMng::Get();
	PartyMng->OnLoadComplete.AddDynamic(this,&AStoryMng::StartStoryLoadPartyComplete);
	PartyMng->LoadParty(&ActiveStory->Party);

}

void AStoryMng::StartStoryLoadPartyComplete()
{
	
	Log.Write(AAUTH, LNORM, VNONE, 1, 0, "Loading Party Complete.");

	UAreaOverride* AreaOverride = NewObject<UAreaOverride>(this, UAreaOverride::StaticClass());
	ActiveStory->PostStart(AreaOverride);

	AAreaMng* AreaMng = AAreaMng::Get();

	if (AreaOverride->IsActive())
	{
		Log.Write(AAUTH, LNORM, VNONE, 1, 0, "Area Override is Active.");
		AreaMng->ChangeArea(AreaOverride->Area_, AreaOverride->Address_);
	}

	AreaOverride->ConditionalBeginDestroy();

}

void AStoryMng::AddCompanionToParty(UStory* Story, UCompanion* Companion)
{
	FParty* Party = &Story->Party;
	Party->AddCompanion(Companion);
}