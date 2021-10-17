//Copyright 2015-2019, All Rights Reserved.

#include "Act.h"
#include "Scope.h"
#include "Engine/LevelStreamingDynamic.h"


namespace GlobalSingleton
{
	UAct* gAct;
}

UAct::UAct() 
{
	bMapLoaded = false;
};

void UAct::Mount()
{
	MountBP();
}

void UAct::Dismount()
{
	DismountBP();
}


void UAct::LoadMap(FString LevelName)
{
	bool bFound = true;
	StreamedLevel_ = ULevelStreamingDynamic::LoadLevelInstance(ScopeC::WorldContext(), LevelName, FVector(0.0f), FRotator(0.0f), bFound);
	StreamedLevel_->OnLevelLoaded.AddDynamic(this, &UAct::OnLevelStreamed);
}

void UAct::OnLevelStreamed()
{

}