// Fill out your copyright notice in the Description page of Project Settings.

#include "log_manager.h"

namespace Global
{
	ALogManager* LogManager;
}


ALogManager* ALogManager::Create(AActor* WorldActor)
{
	ALogManager* N = WorldActor->GetWorld()->SpawnActor<ALogManager>(FVector(0.0f, 0.0f, 0.0f), FRotator(0.0f, 0.0f, 0.0f));
	Global::LogManager = N;
	return N;
}

ALogManager* ALogManager::Get()
{
	return Global::LogManager;
}


bool ALogManager::TryAddLog(FLogger& Output, FString Name)
{
	bool bSuccess = false;
	
	if(Logs.Contains(Name))
	{
		Output = FLogger(Name);
		Logs.Add(Name, Output);
		bSuccess = true;
	}

	return bSuccess;
}

bool ALogManager::TryGetLog(FLogger& Output, FString Name)
{
	bool bSuccess = false;

	if (Logs.Contains(Name))
	{
		Output = Logs.FindRef(Name);
		bSuccess = true;
	}

	return bSuccess;
}