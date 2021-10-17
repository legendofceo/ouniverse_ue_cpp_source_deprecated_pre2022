// Fill out your copyright notice in the Description page of Project Settings.

#include "area_manager.h"
#include "area.h"
#include "data_address.h"
#include "data_fetch.h"


namespace Global
{
	AAreaManager* Cosmos;
}

AAreaManager::AAreaManager() 
{
	ActiveArea = nullptr;
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


void AAreaManager::TravelToArea(FAreaAddress InAddress)
{

	Log.Write("Attempting to travel to Area: "+FString(InAddress.DataAddress()), ELogStatus::Expected);
	FetchDataS Fetch = FetchDataS(InAddress.DataAddress());

	if (Fetch.Success())
	{
		Log.Write("Area was found: " + FString(InAddress.DataAddress()), ELogStatus::Expected);
		AArea* Area = AArea::CreateFromData(this,Fetch.Form);
		ActiveArea = Area;
		Attach(Area);
		Area->Start();
		
	}
	else
	{
		Log.Write("Area was not found: " + FString(InAddress.DataAddress()), ELogStatus::Notice);
	}
}