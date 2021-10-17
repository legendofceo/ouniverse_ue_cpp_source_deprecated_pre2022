// Fill out your copyright notice in the Description page of Project Settings.


#include "AppMode.h"
#include "Kismet/GameplayStatics.h"
#include "Logic.h"
#include "SoftServe.h"
#include "AreaLib.h"
#include "CompanionLib.h"
#include "StoryLib.h"
#include "Mng/PlayerMng.h"
#include "Mng/StoryMng.h"
#include "Mng/PlaythroughMng.h"
#include "Mng/PartyMng.h"
#include "Mng/AreaMng.h"

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
	BootSS = NewObject<USoftServe>(this, USoftServe::StaticClass());
	BootSS->Add(AreaLibClass);
	BootSS->Add(CompanionLibClass);
	BootSS->Add(StoryLibClass);
	BootSS->Add(PlayerMngClass);
	BootSS->Add(PlaythroughMngClass);
	BootSS->Add(StoryMngClass);
	BootSS->Add(AreaMngClass);
	BootSS->Add(PartyMngClass);

	if(BootSS->HasNull())
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "A Manager SoftClass is not correctly set in AppMode");
		Log.Write(AAUTH,LCRIT,VNONE,1,0, "A Manager SoftClass was not correctly set.");
		return;
	}

	BootSS->OnComplete.AddDynamic(this,&AAppMode::BootLL);
	BootSS->Stream();
}

void AAppMode::BootLL(USoftServe* SoftServe)
{
	Log.Write(AAUTH,LNORM,VNONE,1,0, "Boot Lazy Load Started. SoftClasses have been Async Loaded.");



	AreaLib = NewObject<UAreaLib>(this,AreaLibClass.Get());
	AreaLib->SetID("AreaLib");
	Libs.Add(AreaLib);
	
	CompanionLib = NewObject<UCompanionLib>(this, CompanionLibClass.Get());
	CompanionLib->SetID("CompanionLib");
	Libs.Add(CompanionLib);

	StoryLib = NewObject<UStoryLib>(this, StoryLibClass.Get());
	StoryLib->SetID("StoryLib");
	Libs.Add(StoryLib);

	for (ULib* Lib : Libs)
	{
		InitTasks.Add(Lib);
		Lib->OnInitComplete.AddDynamic(this, &AAppMode::InitComplete);
	}

	for (ULib* Lib : Libs)
	{
		Lib->Init();
	}


	FTransform SpawnTransform = FTransform(FRotator(0.0f, 0.0f, 0.0f), FVector(0.0f, 0.0f, 0.0f), FVector(1.0f, 1.0f, 1.0f));
	ESpawnActorCollisionHandlingMethod CollisionMethod = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	StoryMng = GetWorld()->SpawnActorDeferred<AStoryMng>(StoryMngClass.Get(), SpawnTransform, this, NULL, CollisionMethod);
	Managers.Add(StoryMng);

	PlaythroughMng = GetWorld()->SpawnActorDeferred<APlaythroughMng>(PlaythroughMngClass.Get(), SpawnTransform, this, NULL, CollisionMethod);
	Managers.Add(PlaythroughMng);
	
	AreaMng = GetWorld()->SpawnActorDeferred<AAreaMng>(AreaMngClass.Get(), SpawnTransform, this, NULL, CollisionMethod);
	Managers.Add(AreaMng);

	PartyMng = GetWorld()->SpawnActorDeferred<APartyMng>(PartyMngClass.Get(), SpawnTransform, this, NULL, CollisionMethod);
	Managers.Add(PartyMng);


	for (AManagerActor* Manager : Managers)
	{
		InitTasks.Add(Manager);
		Manager->OnInitComplete.AddDynamic(this, &AAppMode::InitComplete);
	}

	for (AManagerActor* Manager : Managers)
	{
		UGameplayStatics::FinishSpawningActor(Manager, SpawnTransform);
		Manager->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
	}

	BootSS->ConditionalBeginDestroy();
	BootSS = NULL;
}

void AAppMode::InitComplete(UObject* Object)
{
	InitTasks.Remove(Object);
	
	if (InitTasks.Num() == 0)
	{
		Log.Write(AAUTH, LNORM, VNONE, 1, 0, "Init Pass 1 completed");
		InitTasks.Reset();

		for (ULib* Lib : Libs)
		{
			InitTasks.Add(Lib);
			Lib->OnInitComplete.RemoveDynamic(this, &AAppMode::InitComplete);
			Lib->OnInitComplete.AddDynamic(this, &AAppMode::BootPostInitComplete);
		}

		for (ULib* Lib : Libs)
		{
			Lib->PostInit();
		}

	}
}

void AAppMode::BootPostInitComplete(UObject* Object)
{
	InitTasks.Remove(Object);

	if (InitTasks.Num() == 0)
	{
		Log.Write(AAUTH, LNORM, VNONE, 1, 0, "Init Pass 2 completed");
		BootComplete();
	}
}

void AAppMode::BootComplete()
{
	Log.Write(AAUTH,LNORM,VNONE,1,0, "BootCompleted()");
	bSuccess = true;
		
	PlaythroughMng->NewGame();
	PlaythroughMng->StartGame();
}






ULogic* AAppMode::DoLogic(TSubclassOf<ULogic> Logic)
{
	ULogic* RunLogic = NewObject<ULogic>(this, Logic);
	RunLogic->DoLogic();
	return RunLogic;
}