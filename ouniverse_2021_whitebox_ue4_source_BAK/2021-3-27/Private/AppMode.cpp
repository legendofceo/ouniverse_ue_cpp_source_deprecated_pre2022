// Fill out your copyright notice in the Description page of Project Settings.


#include "AppMode.h"
#include "Engine/StreamableManager.h"
#include "Engine/AssetManager.h"
#include "Mem.h"
#include "Logic.h"

#include "Mng/AreaMng.h"
#include "Mng/CompanionMng.h"
#include "Mng/PlayerMng.h"
#include "Mng/MemMng.h"
#include "Mng/StoryMng.h"
#include "Mng/PartyMng.h"
#include "Mng/PlaythroughMng.h"

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
	Log.SetID("AppMode");
	Super::BeginPlay();
}

void AAppMode::Boot()
{	
	
	if (AreaMngClass == NULL || CompanionMngClass == NULL || MemMngClass == NULL || PlayerMngClass == NULL || PlaythroughMngClass == NULL || StoryMngClass == NULL || SquadMngClass == NULL)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "A Manager SoftClass is not correctly set in AppMode");
		Log.Write(LCRIT, VNONE, 1, 0, "A Manager SoftClass was not correctly set.");
		Failed = true;
		return;
	}

	if (MemClass == NULL)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "Mem SoftClass is not correctly set in AppMode");
		Log.Write(LCRIT, VNONE, 1, 0, "AppMem SoftClass was not correctly set.");
		Failed = true;
		return;
	}

	TArray<FSoftObjectPath> ItemsToStream;
	FStreamableManager& Streamable = UAssetManager::GetStreamableManager();
	ItemsToStream.AddUnique(AreaMngClass.ToSoftObjectPath());
	ItemsToStream.AddUnique(CompanionMngClass.ToSoftObjectPath());
	ItemsToStream.AddUnique(MemMngClass.ToSoftObjectPath());
	ItemsToStream.AddUnique(PlayerMngClass.ToSoftObjectPath());
	ItemsToStream.AddUnique(PlaythroughMngClass.ToSoftObjectPath());
	ItemsToStream.AddUnique(StoryMngClass.ToSoftObjectPath());
	ItemsToStream.AddUnique(SquadMngClass.ToSoftObjectPath());
	ItemsToStream.AddUnique(MemClass.ToSoftObjectPath());
	
	Streamable.RequestAsyncLoad(ItemsToStream, FStreamableDelegate::CreateUObject(this, &AAppMode::BootLL));
}

void AAppMode::BootLL()
{
	Log.Write(LNORM, VNONE, 1, 0, "Boot Lazy Load Started. SoftClasses have been Async Loaded.");

	FVector Location(0.0f, 0.0f, 0.0f);
	FRotator Rotation(0.0f, 0.0f, 0.0f);
	FActorSpawnParameters SpawnInfo;
	SpawnInfo.bNoFail = true;
	Mem = GetWorld()->SpawnActor<AMem>(MemClass.Get(), Location, Rotation, SpawnInfo);

	AreaMng = NewObject<UAreaMng>(this, AreaMngClass.Get(), TEXT("AreaManager"));
	AreaMng->RegisterComponent();
	AreaMng->Init();

	CompanionMng = NewObject<UCompanionMng>(this, CompanionMngClass.Get(), TEXT("CompanionManager"));
	CompanionMng->RegisterComponent();
	CompanionMng->Init();

	MemMng = NewObject<UMemMng>(this, MemMngClass.Get(), TEXT("MemManager"));
	MemMng->RegisterComponent();
	MemMng->Init(Mem);

	PlayerMng = NewObject<UPlayerMng>(this, PlayerMngClass.Get(), TEXT("PlayerManager"));
	PlayerMng->RegisterComponent();
	PlayerMng->Init(this);
	
	PlaythroughMng = NewObject<UPlaythroughMng>(this, PlaythroughMngClass.Get(), TEXT("PlaythroughManager"));
	PlaythroughMng->RegisterComponent();
	PlaythroughMng->Init();

	StoryMng = NewObject<UStoryMng>(this, StoryMngClass.Get(), TEXT("StoryManager"));
	StoryMng->RegisterComponent();
	StoryMng->Init();

	SquadMng = NewObject<UPartyMng>(this, SquadMngClass.Get(), TEXT("SquadManager"));
	SquadMng->RegisterComponent();
	SquadMng->Init();
}


void AAppMode::BootComplete()
{
	APlaythrough* Playthrough = Mem->Playthrough;

	Log.Write(LNORM, VNONE, 1, 0, "Init II on Managers.");

	AreaMng->InitII();
	CompanionMng->InitII(Playthrough);
	MemMng->InitII();
	SquadMng->InitII(Playthrough,CompanionMng);	
	PlayerMng->InitII();
	PlaythroughMng->InitII(Playthrough,StoryMng);
	StoryMng->InitII(Playthrough,SquadMng,AreaMng);

	Log.Write(LNORM, VNONE, 1, 0, "Boot Complete.");
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