// Fill out your copyright notice in the Description page of Project Settings.


#include "Pro/Maestro.h"
#include "Pro/Splash/SplashPro.h"
#include "Pro/World/WorldPro.h"

UMaestro* UMaestro::Create(AControl* InControl, UUi* InUi)
{
	UMaestro* Neu = NewObject<UMaestro>();
	Neu->Init(InControl, InUi);
	return Neu;
}

void UMaestro::Init(AControl* InControl, UUi* InUi)
{
	Splash_ = USplashPro::Create();

	Universe_ = UWorldPro::Create();
}

void UMaestro::Start()
{
	Dock_.Go(Splash_);
}