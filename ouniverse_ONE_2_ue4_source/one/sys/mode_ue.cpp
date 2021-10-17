// Fill out your copyright notice in the Description page of Project Settings.

#include "mode_ue.h"
#include "Kismet/GameplayStatics.h"
#include "hud_ue.h"
#include "defaultpawn_ue.h"
#include "control_ue.h"

AModeUE* AModeUE::Get(AActor* WorldActor)
{
	return Cast<AModeUE>(UGameplayStatics::GetGameMode(WorldActor));
}

AModeUE::AModeUE()
{
	//PlayerControllerClass = 
	HUDClass = AHudUE::StaticClass();
	DefaultPawnClass = ADefaultPawnUE::StaticClass();
	PlayerControllerClass = AControlUE::StaticClass();
	Dock = CreateDefaultSubobject<USceneComponent>(TEXT("Dock"));
	Dock->SetupAttachment(RootComponent);
}