// Fill out your copyright notice in the Description page of Project Settings.


#include "AppMode.h"
#include "Log.h"
#include "AppInstance.h"
#include "AppController.h"
#include "Kismet/GameplayStatics.h"
#include "SoftServe.h"

#include "MythPro.h"

const FName AAppMode::SYS = "MODE";

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
	App = UApp::Get();
	Super::BeginPlay();
}

void AAppMode::Boot()
{	


	SS = NewObject<USoftServe>(this, USoftServe::StaticClass());
	SS->Add(MythProClass);

	if(SS->HasNull())
	{
		LOG.S(SYS).T(TCRIT).W("A SoftServe class is null. (AppMode)").DebugM();
		return;
	}

	SS->OnComplete.AddDynamic(this,&AAppMode::Boot_SS);
	SS->Stream();

}

void AAppMode::Boot_SS(USoftServe* SoftServe)
{
	LOG.S(SYS).W("Boot_SS()");

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
		LOG.S(SYS).W("SubInitComplete()");
		ConnectPendingPlayers();
		SetPro(EAppPros::Myth);

		ULogger::Get()->OutputTextFile("SubInitComplete() (AppMode)");

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

	//for (AAppController* CTR : AppControllers)
	//{
	//	CTR->Engage_SER();
	//}

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
	LOG.S(SYS).W("New player has connected").DebugM();

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
	LOG.S(SYS).W("Adding Local Player").DebugM();
	AAppController* NewController = Cast<AAppController>(UGameplayStatics::CreatePlayer(this, 1, true));
	AppControllers.Add(NewController);
}


bool AAppMode::IsMultiplayer()
{
	return bMultiplayer;
}