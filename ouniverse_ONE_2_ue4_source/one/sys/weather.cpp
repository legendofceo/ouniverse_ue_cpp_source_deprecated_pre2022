// Fill out your copyright notice in the Description page of Project Settings.

#include "weather.h"



namespace Global
{
	AWeatherManager* WeatherManager;
}


AWeatherManager* AWeatherManager::Create(AActor* WorldActor)
{
	AWeatherManager* N = WorldActor->GetWorld()->SpawnActor<AWeatherManager>(FVector(0.0f, 0.0f, 0.0f), FRotator(0.0f, 0.0f, 0.0f));
	Global::WeatherManager = N;
	return N;
}

AWeatherManager* AWeatherManager::Get()
{
	return Global::WeatherManager;
}
