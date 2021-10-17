// Fill out your copyright notice in the Description page of Project Settings.


#include "AppPlayer.h"
#include "AppController.h"
#include "Pro/AppPro.h"
#include "Cam.h"
#include "Components/SceneComponent.h"

// Sets default values for this component's properties
AAppPlayer::AAppPlayer()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryActorTick.bCanEverTick = false;
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);
	// ...
}


// Called when the game starts
void AAppPlayer::BeginPlay()
{
	Super::BeginPlay();

	FVector Location(0.0f, 0.0f, 0.0f);
	FRotator Rotation(0.0f, 0.0f, 0.0f);
	FActorSpawnParameters SpawnInfo;
	SpawnInfo.bNoFail = true;
	Cam = GetWorld()->SpawnActor<ACam>(ACam::StaticClass(), Location, Rotation, SpawnInfo);
	Cam->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
}

void AAppPlayer::SetAppController(AAppController* InAppController)
{
	AppController = InAppController;
	AppController->SetAppPlayer(this);
	AppController->SetViewTarget(Cam);
}

void AAppPlayer::SetCamTarget(UCameraComponent* CamTarget)
{
	Cam->SetTarget(CamTarget);
}

void AAppPlayer::SetAppPro(AAppPro* InAppPro)
{
	AppPro = InAppPro;
}

bool AAppPlayer::IsOccupied()
{
	if (AppController == NULL)
	{
		return false;
	}

	return true;
}

void AAppPlayer::PlayerSignBT(UInputButtonEvent* BT)
{
	AppPro->RouteBT(BT);
}

void AAppPlayer::PlayerSignAX(UInputButtonEvent* Event)
{

}