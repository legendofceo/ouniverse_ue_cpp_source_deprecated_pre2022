// Fill out your copyright notice in the Description page of Project Settings.


#include "Task/CompanionLoadTask.h"
#include "Lib/CompanionLib.h"
#include "AppMode.h"
#include "Engine/StreamableManager.h"
#include "Engine/AssetManager.h"
#include "Companion.h"
#include "CompanionActor.h"

void UCompanionLoadTask::Setup(UCompanion* InCompanion)
{
	Companion = InCompanion;
}


void UCompanionLoadTask::Go()
{
	if (Companion->EmbodyActraClass.IsValid())
	{
		FVector Location(0.0f, 0.0f, 0.0f);
		FRotator Rotation(0.0f, 0.0f, 0.0f);
		FActorSpawnParameters SpawnInfo;
		SpawnInfo.bNoFail = true;
		ACompanionActor* Actor = GetWorld()->SpawnActor<ACompanionActor>(Companion->EmbodyActraClass.Get(), Location, Rotation, SpawnInfo);
		Actor->OnEmbodyComplete.AddDynamic(this, &UCompanionLoadTask::Complete);
		Actor->BeginEmbody(Companion);
	}
	else if (Companion->EmbodyActraClass.IsNull())
	{
		//AAppMode::GetAppMode(this)->CompanionMng->Log.Write(LCRIT, VNONE, 0, 0, "A Companion Actor Class was NULL: MKey: " + FString::FromInt(Companion->Key) + " (UCompanionLoadTask::LoadLoop)");
	}
	else
	{
		FStreamableManager& Streamable = UAssetManager::GetStreamableManager();
		Streamable.RequestAsyncLoad(Companion->EmbodyActraClass.ToSoftObjectPath(), FStreamableDelegate::CreateUObject(this, &UCompanionLoadTask::Go));
	}
}