// Fill out your copyright notice in the Description page of Project Settings.


#include "Pro/StoryPro.h"
#include "Engine/StreamableManager.h"
#include "Engine/AssetManager.h"
#include "Story.h"
#include "Pro/AppPro.h"
#include "Pro/PartyPro.h"
#include "Area.h"
#include "Party.h"

namespace Global
{
	UStoryPro* StoryPro;
}

UStoryPro* UStoryPro::Get()
{
	return Global::StoryPro;
}

void UStoryPro::GetStoryProBP(UStoryPro*& StoryPro)
{
	StoryPro = Global::StoryPro;
}

void UStoryPro::BeginPlay()
{
	Global::StoryPro = this;
	Super::BeginPlay();
}

void UStoryPro::Init(UAppPro* InAppPro)
{
	AppPro = InAppPro;

	if (PartyProClass == NULL)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "PartyPro is not set in StoryPro");
		return;
	}
	
	FStreamableManager& Streamable = UAssetManager::GetStreamableManager();
	Streamable.RequestAsyncLoad(PartyProClass.ToSoftObjectPath(), FStreamableDelegate::CreateUObject(this, &UStoryPro::InitLL));
}

void UStoryPro::InitLL()
{

}

void UStoryPro::InitSO()
{
	Initialized = true;
	OnInitComplete.Broadcast();
}

void UStoryPro::LoadStory(UStory* InStory)
{
	Story = InStory;
	UParty* Party = Story->GetParty();
	Party->OnEmbodyPartyComplete.AddDynamic(this, &UStoryPro::BufferPartyComplete);
	Party->Load();
}

void UStoryPro::BufferPartyComplete()
{
	if (Story->HasAreaAddressOverride())
	{
		DoChangeArea(Story->GetAreaAddressOverride());
		Story->ClearAreaAddressOverride();
	}
}



void UStoryPro::DoChangeArea(FAreaAddress NextArea)
{
	PendingAreaAddress = NextArea;

	if (Area != NULL)
	{
		Area->OnUnloaded.AddDynamic(this, &UStoryPro::AreaUnloaded);
		Area->Unload();
	}
	else
	{
		AreaUnloaded();
	}
	
}

void UStoryPro::AreaUnloaded()
{
	if (PendingAreaAddress.IsValid())
	{
		//Doing this incase asynch load finished in same thread:
		FSoftObjectPath SoftObjectPath = PendingAreaAddress.Area.ToSoftObjectPath();
		FStreamableManager& Streamable = UAssetManager::GetStreamableManager();
		Streamable.RequestAsyncLoad(PendingAreaAddress.Area.ToSoftObjectPath(), FStreamableDelegate::CreateUObject(this, &UStoryPro::LoadNextArea));
	}
}

void UStoryPro::LoadNextArea()
{
	AreaAddress = PendingAreaAddress;
	PendingAreaAddress.Invalidate();
	Area = NewObject<UArea>(this, AreaAddress.Area.Get());
	Area->Load(AreaAddress.Address);
}

TArray<ACompanionActor*> UStoryPro::GetPartyActors()
{
	return Story->Party->GetPartyActors();
}