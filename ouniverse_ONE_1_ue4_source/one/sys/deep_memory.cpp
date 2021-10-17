// Fill out your copyright notice in the Description page of Project Settings.

#include "deep_memory.h"
#include "../type/json.h"
#include "file_manager.h"

namespace Global
{
	ADeepMemory* DeepMemory;
}

ADeepMemory::ADeepMemory()
{

}

ADeepMemory* ADeepMemory::Create(AActor* WorldActor)
{
	Global::DeepMemory = WorldActor->GetWorld()->SpawnActor<ADeepMemory>(FVector(0.0f, 0.0f, 0.0f), FRotator(0.0f, 0.0f, 0.0f));
	Global::DeepMemory->Constructor();
	return Global::DeepMemory;
}

ADeepMemory* ADeepMemory::Get()
{
	return Global::DeepMemory;
}

void ADeepMemory::Constructor()
{

}

void ADeepMemory::Load()
{
	Path = AFileManager::GetWritableFolder() + ".deepmem";
	bool bDocExists = AFileManager::DoesFileExist(Path);
	if (bDocExists)
	{
		FString FileData;
		FFileHelper::LoadFileToString(FileData, *Path);

		if (JsonS::IsValidJson(FileData))
		{
			JsonS J;
			J.Parse(FileData);
			J.TryInt(LastUserUID, "last_user");

		}
		else
		{
			Log.Write("Json is not valid.", ELogStatus::Warning);
		}

	}
	else
	{
		Log.Write("No Deep Memory document exists. Creating default document.", ELogStatus::Notice);
	}
}