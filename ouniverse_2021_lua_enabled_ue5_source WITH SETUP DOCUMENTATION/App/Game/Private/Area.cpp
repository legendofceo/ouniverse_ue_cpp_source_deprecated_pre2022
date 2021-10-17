// Fill out your copyright notice in the Description page of Project Settings.


#include "Area.h"
#include "Log.h"
#include "AppWorld.h"
#include "Engine/LevelStreamingDynamic.h"
#include "LevelAreaInterface.h"
#include "Engine/LevelScriptActor.h"

const FName UArea::SYS = "AreaNew";

void UArea::LoadLevel(TSoftObjectPtr<UWorld> Level, const FDelDynamicObject& Callback)
{
	OnLoadLevelComplete = Callback;

	bool bFound;
	LevelStreamingDynamic = ULevelStreamingDynamic::LoadLevelInstanceBySoftObjectPtr(UAppWorld::GetAppWorld(), Level, FVector(0.0f), FRotator(0.0f), bFound);
	LevelStreamingDynamic->OnLevelLoaded.AddDynamic(this, &UArea::LevelLoaded);
	//LevelStreamingDynamic = ULevelStreamingDynamic::LoadLevelInstance(UAppWorld::GetAppWorld(), "test_level", FVector(0.0f), FRotator(0.0f), bFound);

	if (bFound)
	{
		LOG.S(SYS).T(TNORM).W("Level Found: "+Level.ToString());
	}
	else
	{
		LOG.S(SYS).T(TCRIT).W("Level Not Found: "+Level.ToString()).DebugM();
	}
}

void UArea::LevelLoaded()
{


	LOG.S(SYS).T(TNORM).W("Level Load Complete");
	LevelScriptActor = LevelStreamingDynamic->GetLevelScriptActor();
	
	if (!LevelScriptActor->GetClass()->ImplementsInterface(ULevelAreaInterface::StaticClass()))
	{
		LOG.S(SYS).T(TCRIT).W("Loaded level does not have the proper interface (LevelAreaInterface)").DebugM();
	}
	else
	{
		OnLoadLevelComplete.Execute(LevelScriptActor);
	}

}

void UArea::StartLevel(UArea* Area)
{
	ILevelAreaInterface::Execute_LevelAreaBeginStart(LevelScriptActor,Area);
}
/**
void UArea::DoLoadMap(TSoftObjectPtr<UWorld> NextMap)
{
	//AAppMode::GetAppMode(this)->DoMapStream(NextMap);
	
	
	FLatentActionInfo LatentInfo;
	LatentInfo.CallbackTarget = this;
	LatentInfo.ExecutionFunction = "MapLoaded";
	UGameplayStatics::LoadStreamLevelBySoftObjectPtr(this, NextMap, true, false, LatentInfo);


	//StreamedDynamic = ULevelStreamingDynamic::LoadLevelInstanceBySoftObjectPtr(this, NextMap, FVector(0.0f), FRotator(0.0f), bFound);
	//StreamedDynamic->OnLevelLoaded.AddDynamic(this, &UArea::MapLoaded);
}
*/