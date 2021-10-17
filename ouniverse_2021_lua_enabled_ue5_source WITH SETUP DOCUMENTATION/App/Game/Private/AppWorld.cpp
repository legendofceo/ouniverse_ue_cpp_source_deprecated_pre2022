// Fill out your copyright notice in the Description page of Project Settings.


#include "AppWorld.h"
#include "Kismet/GameplayStatics.h"
#include "AppInstance.h"


const FName UAppWorld::SYS = "AppWorld";

namespace Global
{
	UAppWorld* AppWorld = nullptr;
}

void UAppWorld::Init(UWorld* InWorld, UObject* InWorldContextObject)
{
	Global::AppWorld = this;
	World = InWorld;
	WorldContextObject = InWorldContextObject;
	bInit = true;
}

UAppWorld* UAppWorld::Get()
{
	return Global::AppWorld;
}

UWorld* UAppWorld::GetAppWorld()
{
	return Global::AppWorld->World;
}

UObject* UAppWorld::GetAppWorldContextObject()
{
	return Global::AppWorld->WorldContextObject;
}