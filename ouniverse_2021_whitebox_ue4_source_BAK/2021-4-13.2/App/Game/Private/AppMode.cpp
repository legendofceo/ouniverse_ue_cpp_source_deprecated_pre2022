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
		Log.W("A SoftServe class is null. (AppMode)").Type(TCRIT).DM().UE();
		return;
	}

	SS->OnComplete.AddDynamic(this,&AAppMode::Boot_SS);
	SS->Stream();

}

void AAppMode::Boot_SS(USoftServe* SoftServe)
{
	Log.W("Boot_SS()").UE();

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
		Log.W("SubInitComplete()").UE();
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
	Log.W("New player has connected").DM().UE();

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
	Log.W("Adding Local Player").DM().UE();
	AAppController* NewController = Cast<AAppController>(UGameplayStatics::CreatePlayer(this, 1, true));
	AppControllers.Add(NewController);
}


bool AAppMode::IsMultiplayer()
{
	return bMultiplayer;
}