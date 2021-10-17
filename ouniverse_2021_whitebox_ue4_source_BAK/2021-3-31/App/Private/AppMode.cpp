// Fill out your copyright notice in the Description page of Project Settings.


#include "AppMode.h"
#include "Kismet/GameplayStatics.h"
#include "Logic.h"
#include "SoftServe.h"
#include "Lib/AreaLib.h"
#include "Lib/CompanionLib.h"
#include "Lib/StoryLib.h"
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

	if(!BootSS->NullCheck())
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "A Manager SoftClass is not correctly set in AppMode");
		Log.Write(AAUTH,LCRIT,VNONE,1,0, "A Manager SoftClass was not correctly set.");
		Failed = true;
		return;
	}

	BootSS->OnComplete.AddDynamic(this,&AAppMode::BootLL);
	BootSS->Stream();
}

void AAppMode::BootLL(USoftServe* SoftServe)
{
	Log.Write(AAUTH,LNORM,VNONE,1,0, "Boot Lazy Load Started. SoftClasses have been Async Loaded.");




	TArray<ULib*> Libs;
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
		Lib->Init();
	}




	FTransform SpawnTransform = FTransform(FRotator(0.0f, 0.0f, 0.0f), FVector(0.0f, 0.0f, 0.0f), FVector(1.0f, 1.0f, 1.0f));
	ESpawnActorCollisionHandlingMethod CollisionMethod = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	TArray<AManagerActor*> Managers;
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
		BootComplete();
	}
}

void AAppMode::BootComplete()
{
	Log.Write(AAUTH,LNORM,VNONE,1,0, "BootCompleted()");

		
	PlaythroughMng->NewGame();
	PlaythroughMng->StartGame();


	//LoadStory();
}






ULogic* AAppMode::DoLogic(TSubclassOf<ULogic> Logic)
{
	ULogic* RunLogic = NewObject<ULogic>(this, Logic);
	RunLogic->DoLogic();
	return RunLogic;
}