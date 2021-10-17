// Fill out your copyright notice in the Description page of Project Settings.


#include "Mng/StoryMng.h"
#include "Mng/PartyMng.h"
#include "Mng/AreaMng.h"
#include "Playthrough.h"
#include "Story.h"
#include "Party.h"

UStoryMng::UStoryMng()
{
	PrimaryComponentTick.bCanEverTick = false;
}



void UStoryMng::BeginPlay()
{
	Super::BeginPlay();

}

void UStoryMng::Init()
{

}

void UStoryMng::InitII(APlaythrough* InPlaythrough,UPartyMng* InPartyMng, UAreaMng* InAreaMng)
{
	Playthrough = InPlaythrough;
	PartyMng = InPartyMng;
	AreaMng = InAreaMng;
}


void UStoryMng::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

void UStoryMng::Start()
{
	AStory* Story = Playthrough->GetActiveStory();
	if (!PartyMng->Loaded)
	{
		PartyMng->OnLoaded.AddDynamic(this, &UStoryMng::Start);
		PartyMng->Load();
	}
	else
	{
		PartyMng->OnLoaded.RemoveDynamic(this, &UStoryMng::Start);

		if (Story->HasAreaAddressOverride())
		{
			AreaMng->DoChangeArea(Story->GetAreaAddressOverride());
			Story->ClearAreaAddressOverride();
		}
	}
}