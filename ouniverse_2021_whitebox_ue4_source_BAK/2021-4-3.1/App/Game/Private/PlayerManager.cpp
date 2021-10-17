// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerManager.h"
#include "AppController.h"
#include "Kismet/GameplayStatics.h"

void UPlayerManager::Init()
{


}

void UPlayerManager::ReceivePlayer(AAppController* AppController)
{
	AppController->AppControllerIndex = AppControllers.Num();
	AppControllers.Add(AppController);

	if (AppController->AppControllerIndex == 0)
	{
		BaseController = AppController;
	}
}


void UPlayerManager::AddLocalPlayer()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Magenta, "Adding Local Player");
	AAppController* NewController = Cast<AAppController>(UGameplayStatics::CreatePlayer(this, 1, true));
	AppControllers.Add(NewController);

}

void UPlayerManager::SetAllRemotes(TEnumAsByte<ERemoteModes> InRemoteMode)
{
	RemoteMode = InRemoteMode;

	for (AAppController* AC : AppControllers)
	{
		AC->SetRemoteMode(RemoteMode);
	}
}