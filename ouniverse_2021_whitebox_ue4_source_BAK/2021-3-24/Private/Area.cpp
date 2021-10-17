// Fill out your copyright notice in the Description page of Project Settings.


#include "Area.h"
#include "Engine/LevelStreamingDynamic.h"
#include "Engine/StreamableManager.h"
#include "Engine/AssetManager.h"

#include "AppMode.h"

void UArea::Load(FName Address)
{
	if (AutoMap)
	{
		DoLoadMap(AutoMapClass);
	}
	else
	{
		DoLoadBP(Address);
	}
}

void UArea::Unload()
{
	UnloadComplete();
}

void UArea::LoadComplete()
{
	OnLoaded.Broadcast();
}


void UArea::UnloadComplete()
{
	OnUnloaded.Broadcast();
}

void UArea::DoLoadMap(TSoftObjectPtr<UWorld> NextMap)
{
	//AAppMode::GetAppMode(this)->DoMapStream(NextMap);
	bool bFound;
	StreamedDynamic = ULevelStreamingDynamic::LoadLevelInstanceBySoftObjectPtr(this, NextMap, FVector(0.0f), FRotator(0.0f), bFound);
	StreamedDynamic->OnLevelLoaded.AddDynamic(this, &UArea::MapLoaded);
}

void UArea::MapLoaded()
{

}