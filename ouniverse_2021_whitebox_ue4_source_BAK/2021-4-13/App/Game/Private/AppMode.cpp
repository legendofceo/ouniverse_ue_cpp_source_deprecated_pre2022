// Fill out your copyright notice in the Description page of Project Settings.


#include "AppMode.h"
#include "AppInstance.h"
#include "AppController.h"
#include "Kismet/GameplayStatics.h"
#include "SoftServe.h"

#include "MythPro.h"


namespace Global
{
	AAppMode* AppMode = NULL;
}

AAppMode::AAppMode()
{
	Global::AppMode = this;
}

AAppMode* AAppMode::Get()
{
	return Global::AppMode;
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


	SS = NewObject<USoftServe>(this, USoftServe::StaticClass());
	SS->Add(MythProClass);

	if(SS->HasNull())
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "A Manager SoftClass is not correctly set in AppMode");
		Log.Write(AAUTH,LCRIT,VNONE,1,0, "A Manager SoftClass was not correctly set.");
		return;
	}

	SS->OnComplete.AddDynamic(this,&AAppMode::Boot_SS);
	SS->Stream();

}

void AAppMode::Boot_SS(USoftServe* SoftServe)
{
	Log.Write(AAUTH,LNORM,VNONE,1,0, "Boot Lazy Load Started. SoftClasses have been Async Loaded.");

	MythPro = NewObject<UMythPro>(this, MythProClass.Get());
	TallySystems.Add(MythPro);
	MythPro->OnInitComplete.AddDynamic(this,&AAppMode::SubInitComplete);
	MythPro->Init();

	FVector Location(0.0f, 0.0f, 0.0f);
	FRotator Rotation(0.0f, 0.0f, 0.0f);
	FActorSpawnParameters SpawnInfo;
	SpawnInfo.bNoFail = true;

	SS = NULL;
}

void AAppMode::SubInitComplete(UObject* SystemObj)
{
	if (TallySystems.Complete(SystemObj))
	{
		bInit = true;
		Log.Write(AAUTH, LNORM, VNONE, 1, 0, "BootCompleted()");
		ConnectPendingPlayers();
		SetPro(EAppPros::Myth);
	}
}


void AAppMode::SetPro(EAppPros InPro)
{
	Pro = InPro;

	switch (Pro) {
	case EAppPros::None:

		break;
	case EAppPros::Outer:

		break;
	case EAppPros::Myth:
		MythPro->Engage();
		break;
	}

	for (AAppController* CTR : AppControllers)
	{
		CTR->Engage_SER();
	}

	//MythPro->EnterWorld();
}

void AAppMode::ReceiveNewPlayer(AAppController* AppController)
{
	if (!bInit)
	{
		PendingPlayers.Add(AppController);
	}
	else
	{
		ConnectNewPlayer(AppController);
	}
}

void AAppMode::ConnectPendingPlayers()
{
	for (AAppController* Player : PendingPlayers)
	{
		ConnectNewPlayer(Player);
	}
}

void AAppMode::ConnectNewPlayer(AAppController* AppController)
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Magenta, "New player has connected");

	AppController->AppControllerIndex = AppControllers.Num();
	AppControllers.Add(AppController);

	if (AppController->AppControllerIndex == 0)
	{
		AppController->Host();
		BaseController = AppController;
	}

	AppController->InitAfterServerSystemsReady();
	AppController->Engage_SER();

}

void AAppMode::AddLocalPlayer()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Magenta, "Adding Local Player");
	AAppController* NewController = Cast<AAppController>(UGameplayStatics::CreatePlayer(this, 1, true));
	AppControllers.Add(NewController);
}


bool AAppMode::IsMultiplayer()
{
	return bMultiplayer;
}