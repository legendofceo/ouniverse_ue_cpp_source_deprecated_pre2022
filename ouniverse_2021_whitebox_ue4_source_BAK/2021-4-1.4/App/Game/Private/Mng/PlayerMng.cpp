// Fill out your copyright notice in the Description page of Project Settings.


#include "Mng/PlayerMng.h"
#include "AppMode.h"
#include "AppController.h"
#include "Kismet/GameplayStatics.h"

UPlayerMng::UPlayerMng()
{

	PrimaryComponentTick.bCanEverTick = false;

}



void UPlayerMng::BeginPlay()
{
	Super::BeginPlay();
}


void UPlayerMng::Init(AAppMode* InAppMode)
{
	AppMode = InAppMode;

	for (AAppController* Controller : AppMode->EarlyControllers)
	{
		NewPlayerConnection(Controller);
	}
}

void UPlayerMng::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

void UPlayerMng::NewPlayerConnection(AAppController* AppController)
{
	AppController->AppControllerIndex = AppControllers.Num();
	AppControllers.Add(AppController);

	if (AppController->AppControllerIndex == 0)
	{
		BaseController = AppController;
	}

	AppController->AttachToActor(this->GetOwner(), FAttachmentTransformRules::KeepRelativeTransform);
}

void UPlayerMng::AddLocalPlayer()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Magenta, "Adding Local Player");
	AAppController* NewController = Cast<AAppController>(UGameplayStatics::CreatePlayer(this, 1, true));
	AppControllers.Add(NewController);

}
