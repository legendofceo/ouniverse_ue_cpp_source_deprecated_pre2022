// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelCosmos.h"
#include "Engine/LevelStreamingDynamic.h"


void ALevelCosmos::DoMapStream(TSoftObjectPtr<UWorld> Map)
{
	bool bFound;
	StreamedDynamic = ULevelStreamingDynamic::LoadLevelInstanceBySoftObjectPtr(this, Map, FVector(0.0f), FRotator(0.0f), bFound);
	StreamedDynamic->OnLevelLoaded.AddDynamic(this, &ALevelCosmos::DoMapStreamLL);
}

void ALevelCosmos::DoMapStreamLL()
{

}