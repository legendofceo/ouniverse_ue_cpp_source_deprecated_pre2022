// Fill out your copyright notice in the Description page of Project Settings.

#include "cell.h"
#include "area.h"
#include "level_cell.h"


ACell::ACell()
{

}

ACell* ACell::Create(AArea* InArea, FName InCatalyst)
{
	ACell* N = InArea->GetWorld()->SpawnActor<ACell>(FVector(0.0f, 0.0f, 0.0f), FRotator(0.0f, 0.0f, 0.0f));
	N->Area = InArea;
	N->Catalyst = InCatalyst;
	return N;
}

void ACell::Load()
{
	bool bFound = true;
	//StreamedLevel_ = ULevelStreamingDynamic::LoadLevelInstance(AScope::WorldContext(), LevelName, FVector(0.0f), FRotator(0.0f), bFound);
	//StreamedLevel_ = ULevelStreamingDynamic::LoadLevelInstanceBySoftObjectPtr(this, SOFTPTR, FVector(0.0f), FRotator(0.0f), bFound);
	//StreamedLevel_->OnLevelLoaded.AddDynamic(this, &ACell::OnLevelStreamed);

}

void ACell::OnLevelStreamed()
{
	Level = Cast<ALevelCell>(StreamedLevel_->GetLevelScriptActor());
	Level->Start(Area,Catalyst);
}



void ACell::Unload()
{

}