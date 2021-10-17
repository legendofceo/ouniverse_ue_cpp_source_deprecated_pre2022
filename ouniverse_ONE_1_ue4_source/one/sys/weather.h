// Fill out your copyright notice in the Description page of Project Settings.


#pragma once

#include "base.h"
#include "weather.generated.h"



UCLASS()
class AWeatherManager : public ABase
{

	GENERATED_BODY()

public:

	static AWeatherManager* Create(AActor* WorldActor);
	static AWeatherManager* Get();

};