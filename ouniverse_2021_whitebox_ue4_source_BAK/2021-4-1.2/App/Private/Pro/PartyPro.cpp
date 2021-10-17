// Fill out your copyright notice in the Description page of Project Settings.


#include "Pro/PartyPro.h"
#include "Engine/StreamableManager.h"
#include "Engine/AssetManager.h"

void UPartyPro::BeginPlay()
{
	Super::BeginPlay();
}


void UPartyPro::Init(UStoryPro* InStoryPro)
{
	StoryPro = InStoryPro;


	/**
	if (PartyProClass == NULL)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "PartyPro is not set in StoryPro");
		return;
	}

	FStreamableManager& Streamable = UAssetManager::GetStreamableManager();
	Streamable.RequestAsyncLoad(PartyProClass.ToSoftObjectPath(), FStreamableDelegate::CreateUObject(this, &UStoryPro::InitLL));
	*/

	InitSO();
}

void UPartyPro::InitLL()
{
	/**
	FVector Location(0.0f, 0.0f, 0.0f);
	FRotator Rotation(0.0f, 0.0f, 0.0f);
	FActorSpawnParameters SpawnInfo;
	SpawnInfo.bNoFail = true;
	PartyPro = GetWorld()->SpawnActor<UPartyPro>(PartyProClass.Get(), Location, Rotation, SpawnInfo);
	PartyPro->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
	PartyPro->OnInitComplete.AddDynamid(this, &UStoryPro::InitSO);
	PartyPro->Init(this);
	*/
}

void UPartyPro::InitSO()
{
	Initialized = true;
	OnInitComplete.Broadcast();
}