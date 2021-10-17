// Fill out your copyright notice in the Description page of Project Settings.


#include "AppMode.h"
#include "AppInstance.h"
#include "Kismet/GameplayStatics.h"
#include "Logic.h"
#include "SoftServe.h"
#include "WorldAnnex.h"


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
	App = UApp::Get();
	Super::BeginPlay();
}

void AAppMode::Boot()
{	

	BootSS = NewObject<USoftServe>(this, USoftServe::StaticClass());
	BootSS->Add(WorldAnnexClass);

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

	WorldAnnex = NewObject<UWorldAnnex>(this, WorldAnnexClass.Get());
	WorldAnnex->Init();

	InitComplete(this);
	
	BootSS = NULL;
}

void AAppMode::InitComplete(UObject* Object)
{

	InitTasks.Remove(Object);
	
	if (InitTasks.Num() == 0)
	{

		for (AAppController* AC : EarlyControllers)
		{
			RegisterPlayer(AC);
		}

		Log.Write(AAUTH, LNORM, VNONE, 1, 0, "Init Pass 2 completed");
		BootComplete();

	}

}


void AAppMode::BootComplete()
{
	Log.Write(AAUTH,LNORM,VNONE,1,0, "BootCompleted()");
	bInitialized = true;

	WorldAnnex->EnterWorld();
}












void AAppMode::ReceivePlayer(AAppController* AppController)
{
	if (bInitialized)
	{
		RegisterPlayer(AppController);
	}
	else
	{
		EarlyControllers.Add(AppController);
	}
}

void AAppMode::RegisterPlayer(AAppController* AppController)
{
	AppController->AppControllerIndex = AppControllers.Num();
	AppControllers.Add(AppController);

	if (AppController->AppControllerIndex == 0)
	{
		BaseController = AppController;
	}

	//AppController->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
}

void AAppMode::AddLocalPlayer()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Magenta, "Adding Local Player");
	AAppController* NewController = Cast<AAppController>(UGameplayStatics::CreatePlayer(this, 1, true));
	AppControllers.Add(NewController);

}




ULogic* AAppMode::DoLogic(TSubclassOf<ULogic> Logic)
{
	ULogic* RunLogic = NewObject<ULogic>(this, Logic);
	RunLogic->DoLogic();
	return RunLogic;
}