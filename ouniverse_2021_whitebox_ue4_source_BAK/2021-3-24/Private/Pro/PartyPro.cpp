// Fill out your copyright notice in the Description page of Project Settings.


#include "Pro/PartyPro.h"
#include "Engine/StreamableManager.h"
#include "Engine/AssetManager.h"

void APartyPro::BeginPlay()
{
	Super::BeginPlay();
}


void APartyPro::Init(AStoryPro* InStoryPro)
{
	StoryPro = InStoryPro;


	/**
	if (PartyProClass == NULL)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "PartyPro is not set in StoryPro");
		return;
	}

	FStreamableManager& Streamable = UAssetManager::GetStreamableManager();
	Streamable.RequestAsyncLoad(PartyProClass.ToSoftObjectPath(), FStreamableDelegate::CreateUObject(this, &AStoryPro::InitLL));
	*/

	InitSO();
}

void APartyPro::InitLL()
{
	/**
	FVector Location(0.0f, 0.0f, 0.0f);
	FRotator Rotation(0.0f, 0.0f, 0.0f);
	FActorSpawnParameters SpawnInfo;
	SpawnInfo.bNoFail = true;
	PartyPro = GetWorld()->SpawnActor<APartyPro>(PartyProClass.Get(), Location, Rotation, SpawnInfo);
	PartyPro->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
	PartyPro->OnInitComplete.AddDynamid(this, &AStoryPro::InitSO);
	PartyPro->Init(this);
	*/
}

void APartyPro::InitSO()
{
	Initialized = true;
	OnInitComplete.Broadcast();
}