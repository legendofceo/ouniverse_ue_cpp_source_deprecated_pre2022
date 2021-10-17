// Fill out your copyright notice in the Description page of Project Settings.


#include "AppMode.h"
#include "Engine/StreamableManager.h"
#include "Engine/AssetManager.h"
#include "AppMem.h"
#include "Logic.h"
#include "Story.h"
#include "Party.h"

#include "Mng/AreaMng.h"
#include "Mng/PlayerMng.h"
#include "Mng/MemMng.h"
#include "Mng/StoryMng.h"
#include "Mng/PartyMng.h"
#include "Mng/PlaythroughMng.h"

#include "LogComponent.h"

namespace Global
{
	AAppMode* AppMode = NULL;
}

AAppMode::AAppMode()
{
	Global::AppMode = this;
}

AAppMode* AAppMode::GetAppMode(const UObject* WorldContextObject)
{
	return Cast<AAppMode>(WorldContextObject->GetWorld()->GetAuthGameMode());
}

void AAppMode::BeginPlay()
{
	Log = NewObject<ULogComponent>(this, ULogComponent::StaticClass(), TEXT("ModeLog"));
	Super::BeginPlay();
}

void AAppMode::Boot()
{	

	if (AreaMngClass == NULL || MemMngClass == NULL || PlayerMngClass == NULL || PlaythroughMngClass == NULL || StoryMngClass == NULL || SquadMngClass == NULL)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "A Manager SoftClass is not correctly set in AppMode");
		Log->Write(LCRIT, VNONE, 1, 0, "A Manager SoftClass was not correctly set.");
		Failed = true;
		return;
	}

	if (AppMemClass == NULL)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "A SoftClass is not correctly set in AppMode");
		Log->Write(LCRIT, VNONE, 1, 0, "AppMem SoftClass was not correctly set.");
		Failed = true;
		return;
	}

	TArray<FSoftObjectPath> ItemsToStream;
	FStreamableManager& Streamable = UAssetManager::GetStreamableManager();
	ItemsToStream.AddUnique(AreaMngClass.ToSoftObjectPath());
	ItemsToStream.AddUnique(MemMngClass.ToSoftObjectPath());
	ItemsToStream.AddUnique(PlayerMngClass.ToSoftObjectPath());
	ItemsToStream.AddUnique(PlaythroughMngClass.ToSoftObjectPath());
	ItemsToStream.AddUnique(StoryMngClass.ToSoftObjectPath());
	ItemsToStream.AddUnique(SquadMngClass.ToSoftObjectPath());

	ItemsToStream.AddUnique(AppMemClass.ToSoftObjectPath());
	
	Streamable.RequestAsyncLoad(ItemsToStream, FStreamableDelegate::CreateUObject(this, &AAppMode::BootLL));
}

void AAppMode::BootLL()
{
	Log->Write(LNORM, VNONE, 1, 0, "Boot Lazy Load Started. SoftClasses have been Async Loaded.");

	FVector Location(0.0f, 0.0f, 0.0f);
	FRotator Rotation(0.0f, 0.0f, 0.0f);
	FActorSpawnParameters SpawnInfo;
	SpawnInfo.bNoFail = true;
	AppMem = GetWorld()->SpawnActor<AAppMem>(AppMemClass.Get(), Location, Rotation, SpawnInfo);
	AppMem->OnInitComplete.AddDynamic(this, &AAppMode::BootComplete);

	//Mem must already be created at this point or there will be a crash
	AreaMng = NewObject<UAreaMng>(this, AreaMngClass.Get(), TEXT("AreaManager"));
	AreaMng->RegisterComponent();
	
	MemMng = NewObject<UMemMng>(this, MemMngClass.Get(), TEXT("MemManager"));
	MemMng->RegisterComponent();
	MemMng->Init(AppMem);

	PlayerMng = NewObject<UPlayerMng>(this, PlayerMngClass.Get(), TEXT("PlayerManager"));
	PlayerMng->RegisterComponent();
	PlayerMng->Init(this);
	
	PlaythroughMng = NewObject<UPlaythroughMng>(this, PlaythroughMngClass.Get(), TEXT("PlaythroughManager"));
	PlaythroughMng->RegisterComponent();
	
	StoryMng = NewObject<UStoryMng>(this, StoryMngClass.Get(), TEXT("StoryManager"));
	StoryMng->RegisterComponent();
	
	SquadMng = NewObject<UPartyMng>(this, SquadMngClass.Get(), TEXT("SquadManager"));
	SquadMng->RegisterComponent();

}

//Called from Mem Completing

void AAppMode::BootComplete()
{
	Log->Write(LNORM, VNONE, 1, 0, "Boot Complete.");
	PlaythroughMng->NewGame();
	PlaythroughMng->Start();

	//LoadStory();
}






ULogic* AAppMode::DoLogic(TSubclassOf<ULogic> Logic)
{
	ULogic* RunLogic = NewObject<ULogic>(this, Logic);
	RunLogic->DoLogic();
	return RunLogic;
}









void AAppMode::LoadStory(UStory* InStory)
{
	Story = InStory;
	UParty* Party = Story->GetParty();
	Party->OnEmbodyPartyComplete.AddDynamic(this, &AAppMode::BufferPartyComplete);
	Party->Load();
}


void AAppMode::BufferPartyComplete()
{
	if (Story->HasAreaAddressOverride())
	{
		AreaMng->DoChangeArea(Story->GetAreaAddressOverride());
		Story->ClearAreaAddressOverride();
	}
}

TArray<ACompanionActor*> AAppMode::GetPartyActors()
{
	return Story->Party->GetPartyActors();
}