// Fill out your copyright notice in the Description page of Project Settings.


#include "AppMode.h"
#include "Kismet/GameplayStatics.h"
#include "Logic.h"
#include "SoftServe.h"
#include "AppNexus.h"
#include "PlayerMng.h"
#include "StoryMng.h"
#include "PlaythroughMng.h"
#include "PartyMng.h"
#include "AreaMng.h"

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
	BootSS->Add(PlayerMngClass);
	BootSS->Add(StoryMngClass);

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


	FTransform SpawnTransform = FTransform(FRotator(0.0f, 0.0f, 0.0f), FVector(0.0f, 0.0f, 0.0f), FVector(1.0f, 1.0f, 1.0f));
	ESpawnActorCollisionHandlingMethod CollisionMethod = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	AppNexus = GetWorld()->SpawnActorDeferred<AAppNexus>(AAppNexus::StaticClass(), SpawnTransform, this, NULL, CollisionMethod);
	Managers.Add(AppNexus);

	StoryMng = GetWorld()->SpawnActorDeferred<ACosmNexus>(StoryMngClass.Get(), SpawnTransform, this, NULL, CollisionMethod);
	Managers.Add(StoryMng);

	for (ANexus* Manager : Managers)
	{
		InitTasks.Add(Manager);
		Manager->OnInitComplete.AddDynamic(this, &AAppMode::InitComplete);
	}

	for (ANexus* Manager : Managers)
	{
		UGameplayStatics::FinishSpawningActor(Manager, SpawnTransform);

		if (Manager != AppNexus)
		{
			Manager->AttachToActor(AppNexus, FAttachmentTransformRules::KeepRelativeTransform);
		}
	}

	BootSS = NULL;
}

void AAppMode::InitComplete(UObject* Object)
{

	InitTasks.Remove(Object);
	
	if (InitTasks.Num() == 0)
	{

		for (AAppController* AC : EarlyControllers)
		{
			PlayerMng->NewPlayerConnection(AC);
		}

		Log.Write(AAUTH, LNORM, VNONE, 1, 0, "Init Pass 2 completed");
		BootComplete();

	}

}


void AAppMode::BootComplete()
{
	Log.Write(AAUTH,LNORM,VNONE,1,0, "BootCompleted()");
	bSuccess = true;

	StoryMng->StartGame();
}






ULogic* AAppMode::DoLogic(TSubclassOf<ULogic> Logic)
{
	ULogic* RunLogic = NewObject<ULogic>(this, Logic);
	RunLogic->DoLogic();
	return RunLogic;
}