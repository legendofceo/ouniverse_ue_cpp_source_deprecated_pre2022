// Fill out your copyright notice in the Description page of Project Settings.

#include "hud_ue.h"
#include "Kismet/GameplayStatics.h"

AHudUE::AHudUE()
{
	Dock = CreateDefaultSubobject<USceneComponent>(TEXT("Dock"));
	Dock->SetupAttachment(RootComponent);
}

AHudUE* AHudUE::Get(AActor* WorldActor)
{
	return Cast<AHudUE>(UGameplayStatics::GetPlayerController(WorldActor, 0)->GetHUD());
}