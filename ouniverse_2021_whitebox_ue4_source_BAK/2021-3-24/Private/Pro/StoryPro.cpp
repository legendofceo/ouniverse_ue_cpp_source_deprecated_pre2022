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
	AStoryPro* StoryPro;
}

AStoryPro* AStoryPro::Get()
{
	return Global::StoryPro;
}

void AStoryPro::GetStoryProBP(AStoryPro*& StoryPro)
{
	StoryPro = Global::StoryPro;
}

void AStoryPro::BeginPlay()
{
	Global::StoryPro = this;
	Super::BeginPlay();
}

void AStoryPro::Init(AAppPro* InAppPro)
{
	AppPro = InAppPro;

	if (PartyProClass == NULL)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "PartyPro is not set in StoryPro");
		return;
	}
	
	FStreamableManager& Streamable = UAssetManager::GetStreamableManager();
	Streamable.RequestAsyncLoad(PartyProClass.ToSoftObjectPath(), FStreamableDelegate::CreateUObject(this, &AStoryPro::InitLL));
}

void AStoryPro::InitLL()
{
	FVector Location(0.0f, 0.0f, 0.0f);
	FRotator Rotation(0.0f, 0.0f, 0.0f);
	FActorSpawnParameters SpawnInfo;
	SpawnInfo.bNoFail = true;
	PartyPro = GetWorld()->SpawnActor<APartyPro>(PartyProClass.Get(), Location, Rotation, SpawnInfo);
	PartyPro->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
	PartyPro->OnInitComplete.AddDynamic(this, &AStoryPro::InitSO);
	PartyPro->Init(this);
}

void AStoryPro::InitSO()
{
	Initialized = true;
	OnInitComplete.Broadcast();
}

void AStoryPro::LoadStory(UStory* InStory)
{
	Story = InStory;
	UParty* Party = Story->GetParty();
	Party->OnEmbodyPartyComplete.AddDynamic(this, &AStoryPro::BufferPartyComplete);
	Party->Load();
}

void AStoryPro::BufferPartyComplete()
{
	if (Story->HasAreaAddressOverride())
	{
		DoChangeArea(Story->GetAreaAddressOverride());
		Story->ClearAreaAddressOverride();
	}
}



void AStoryPro::DoChangeArea(FAreaAddress NextArea)
{
	PendingAreaAddress = NextArea;

	if (Area != NULL)
	{
		Area->OnUnloaded.AddDynamic(this, &AStoryPro::AreaUnloaded);
		Area->Unload();
	}
	else
	{
		AreaUnloaded();
	}
	
}

void AStoryPro::AreaUnloaded()
{
	if (PendingAreaAddress.IsValid())
	{
		//Doing this incase asynch load finished in same thread:
		FSoftObjectPath SoftObjectPath = PendingAreaAddress.Area.ToSoftObjectPath();
		FStreamableManager& Streamable = UAssetManager::GetStreamableManager();
		Streamable.RequestAsyncLoad(PendingAreaAddress.Area.ToSoftObjectPath(), FStreamableDelegate::CreateUObject(this, &AStoryPro::LoadNextArea));
	}
}

void AStoryPro::LoadNextArea()
{
	AreaAddress = PendingAreaAddress;
	PendingAreaAddress.Invalidate();
	Area = NewObject<UArea>(this, AreaAddress.Area.Get());
	Area->Load(AreaAddress.Address);
}

TArray<ACompanionActor*> AStoryPro::GetPartyActors()
{
	return Story->Party->GetPartyActors();
}