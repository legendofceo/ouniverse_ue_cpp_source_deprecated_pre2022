// Fill out your copyright notice in the Description page of Project Settings.


#include "AppMode.h"
#include "Engine/StreamableManager.h"
#include "Engine/AssetManager.h"
#include "Kismet/GameplayStatics.h"
#include "AppController.h"
#include "AppPlayer.h"
#include "AppMem.h"
#include "Pro/AppPro.h"
#include "Area.h"
#include "Logic.h"

namespace Global
{
	AAppMode* AppMode;
}

AAppMode::AAppMode()
{
	Global::AppMode = this;
}

AAppMode* AAppMode::GetAppMode(const UObject* WorldContextObject)
{
	return Cast<AAppMode>(WorldContextObject->GetWorld()->GetAuthGameMode());
}







void AAppMode::Boot()
{
	if (AppMemClass == NULL)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "AppMemClass is not set in AppMode");
		return;
	}

	if (AppProClass == NULL)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "AppProClass is not set in AppMode");
		return;
	}

	TArray<FSoftObjectPath> ItemsToStream;
	FStreamableManager& Streamable = UAssetManager::GetStreamableManager();
	ItemsToStream.AddUnique(AppMemClass.ToSoftObjectPath());
	ItemsToStream.AddUnique(AppProClass.ToSoftObjectPath());
	Streamable.RequestAsyncLoad(ItemsToStream, FStreamableDelegate::CreateUObject(this, &AAppMode::BootLL));
}

void AAppMode::BootLL()
{

	FVector Location(0.0f, 0.0f, 0.0f);
	FRotator Rotation(0.0f, 0.0f, 0.0f);
	FActorSpawnParameters SpawnInfo;
	SpawnInfo.bNoFail = true;

	AppPlayers.Init(NULL, 3);
	AppPlayers[0] = GetWorld()->SpawnActor<AAppPlayer>(AAppPlayer::StaticClass(), Location, Rotation, SpawnInfo);
	AppPlayers[1] = GetWorld()->SpawnActor<AAppPlayer>(AAppPlayer::StaticClass(), Location, Rotation, SpawnInfo);
	AppPlayers[2] = GetWorld()->SpawnActor<AAppPlayer>(AAppPlayer::StaticClass(), Location, Rotation, SpawnInfo);

	AppPlayers[0]->SetAppController(BaseController);

	for (AAppPlayer* AppPlayer : AppPlayers)
	{
		AppPlayer->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
	}

	AddLocalPlayer();

	AppPro = GetWorld()->SpawnActor<AAppPro>(AppProClass.Get(), Location, Rotation, SpawnInfo);
	AppMem = GetWorld()->SpawnActor<AAppMem>(AppMemClass.Get(), Location, Rotation, SpawnInfo);

	AppPro->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
	AppMem->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);

	AppMem->OnInitComplete.AddDynamic(this, &AAppMode::SetupAppPro);
	AppMem->BeginInit();
}

void AAppMode::BootComplete()
{
	OnBootComplete.Broadcast();
}







void AAppMode::SetupAppPro()
{
	AppPro->OnInitComplete.AddDynamic(this, &AAppMode::BootComplete);
	AppPro->Init(AppMem);
}





void AAppMode::AddAppController(AAppController* AppController)
{
	AppController->AppControllerIndex = AppControllers.Num();
	AppControllers.Add(AppController);

	if (AppController->AppControllerIndex == 0)
	{
		BaseController = AppController;
		AppController->SetPeripheral(EPeripherals::EPeripheralMouseKeyboardAndGamepad);
	}

	AppController->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
}

void AAppMode::AddLocalPlayer()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Magenta, "Adding Local Player");
	AAppController* NewController = Cast<AAppController>(UGameplayStatics::CreatePlayer(this, 1, true));
	BaseController->SetPeripheral(EPeripherals::EPeripheralMouseAndKeyboard);
	NewController->SetPeripheral(EPeripherals::EPeripheralGamepad1);
	AppControllers.Add(NewController);

}







ULogic* AAppMode::DoLogic(TSubclassOf<ULogic> Logic)
{
	ULogic* RunLogic = NewObject<ULogic>(this, Logic);
	RunLogic->DoLogic();
	return RunLogic;
}