// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerMng.h"
#include "AppMode.h"
#include "AppController.h"
#include "Kismet/GameplayStatics.h"

namespace Manager
{
	APlayerMng* Player = NULL;
}

APlayerMng::APlayerMng() : ANexus() {}

APlayerMng* APlayerMng::Get()
{
	return Manager::Player;
}

void APlayerMng::GetPlayerMngBP(APlayerMng*& PlayerMng)
{
	PlayerMng = Manager::Player;
}

void APlayerMng::BeginPlay()
{

#if UE_BUILD_DEVELOPMENT
	/**
	FBlueEnsureImplementation BEF = FBlueEnsureImplementation();
	BEF.Add("InitBP");
	BEF.Add("PreStartBP");
	BEF.Add("PostStartBP");
	BEF.Go(this, ID.ToString());
	*/
#endif

	Manager::Player = this;
	Log.Write(AAUTH, LNORM, VNONE, 1, 0, "Init()");
	bInit = true;
	OnInitComplete.Broadcast(this);

}



void APlayerMng::NewPlayerConnection(AAppController* AppController)
{
	AppController->AppControllerIndex = AppControllers.Num();
	AppControllers.Add(AppController);

	if (AppController->AppControllerIndex == 0)
	{
		BaseController = AppController;
	}

	//AppController->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
}

void APlayerMng::AddLocalPlayer()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Magenta, "Adding Local Player");
	AAppController* NewController = Cast<AAppController>(UGameplayStatics::CreatePlayer(this, 1, true));
	AppControllers.Add(NewController);

}
