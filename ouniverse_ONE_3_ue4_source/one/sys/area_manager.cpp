// Fill out your copyright notice in the Description page of Project Settings.

#include "area_manager.h"


namespace Global
{
	AAreaManager* Cosmos;
}

AAreaManager::AAreaManager() 
{

}

void AAreaManager::Constructor()
{
	Log = FLogger("Log");
}

AAreaManager* AAreaManager::Create(AActor* WorldActor)
{
	AAreaManager* Neu = WorldActor->GetWorld()->SpawnActor<AAreaManager>(FVector(0.0f, 0.0f, 0.0f), FRotator(0.0f, 0.0f, 0.0f));
	Global::Cosmos = Neu;
	Neu->Constructor();
	return Neu;
}

AAreaManager* AAreaManager::Get()
{
	return Global::Cosmos;
}