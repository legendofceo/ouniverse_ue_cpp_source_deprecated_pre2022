// Fill out your copyright notice in the Description page of Project Settings.

#include "data_manager.h"
#include "file_manager.h"
#include "Engine/DataTable.h"
#include "atlas.h"
#include "loadout.h"
#include "log.h"
#include "EngineUtils.h"

FString UDataManager::AtlasDirName(TEXT("atlas"));
FString UDataManager::AtlasFileEXT("atlas");
FString UDataManager::AtlasDataFileEXT("atlasdata");

namespace Global
{
	UDataManager* DataManager;
}


UDataManager::UDataManager()
{
	AtlasCount = 0;
	AtlasScannedCount = 0;

	bAtlasesLoaded = false;
	bAtlasDataLoaded = false;
}

/**
void ADataManager::EnsureDataManager(UObject* WorldContextObject)
{
	TActorIterator<ADataManager> ActorItr = TActorIterator<ADataManager>(GEngine->GetWorldFromContextObjectChecked(WorldContextObject));

	//While not reached end (overloaded bool operator)
	bool bFound = false;
	while (ActorItr)
	{
		bFound = true;
		++ActorItr;
	}

	if (!bFound)
	{
		ADataManager::Create(WorldContextObject);
	}

}
*/

UDataManager* UDataManager::Create(TSoftClassPtr<UDataManager> SoftClass, UObject* WorldCTX)
{
	Global::DataManager = NewObject<UDataManager>(WorldCTX, SoftClass.LoadSynchronous());
	Global::DataManager->Constructor();
	return Global::DataManager;
}

UDataManager* UDataManager::Get()
{
	return Global::DataManager;
}

UDataManager* UDataManager::GetDataManager()
{
	return UDataManager::Get();
}


void UDataManager::Constructor()
{
	Log = FLogger("Log");

	FString ContextString;
	TArray<FName> RowNames = FormTypeSheet->GetRowNames();
	for (auto& RowName : RowNames)
	{
		FFormTypeRow* Row = FormTypeSheet->FindRow<FFormTypeRow>(RowName, ContextString);
		if (Row)
		{
			UFormType* FormType = UFormType::Create(Row);
			FormTypes.Add(FormType->UID, FormType);
		}
	}

	for (const TPair<int, UFormType*>& pair : FormTypes)
	{
		pair.Value->SetParent();
	}


}

void UDataManager::LoadAtlases()
{
	Log.Write("Loading Atlases...", ELogStatus::Expected);

	AtlasDir = FPaths::ProjectContentDir() + "/" + UDataManager::AtlasDirName + "/";
	AFileManager::NormalizeDir(AtlasDir);
	AFileManager::EnsureDirTree(AtlasDir);

	TArray<FString> Folders = AFileManager::GetAllFoldersInDir(AtlasDir);
	Log.Write("Atlas Directory: " + AtlasDir, ELogStatus::Expected);

	int L = Folders.Num();

	for (int i = 0; i < L; i++)
	{


		if (Folders[i].IsNumeric())
		{
			int32 FolderUID = FCString::Atoi(*Folders[i]);
			Log.Write("Atlas Folder: " + FString::FromInt(FolderUID), ELogStatus::Expected);
			AtlasScannedCount++;
			UAtlas* NewAtlas = NewObject<UAtlas>();
			NewAtlas->Constructor();
			NewAtlas->AtlasFromJsonDocument(FolderUID,&Log);

			if (NewAtlas->IsValid())
			{
				Atlases.Add(NewAtlas->UID, NewAtlas);
				AtlasCount++;
			}
			else
			{

			}
		}
	}

	bAtlasesLoaded = true;
	Log.Write("Loading Atlases Complete", ELogStatus::Expected);

}

ULoadout* UDataManager::GetOfficialLoadout()
{
	ULoadout* Lo = ULoadout::Create("Default");
	Lo->AddEntry(100,"One");
	return Lo;
}

void UDataManager::LoadAtlasDataFromLoadout(ULoadout* Loadout)
{
	Log.Write("Loading Atlas Data from Loadout", ELogStatus::Expected);

	for (const TPair<int, UAtlas*>& Pair : Atlases)
	{
		//Pair.Value->FromJson();
	}

	bAtlasDataLoaded = true;

	Log.Write("Loading AtlasData Complete", ELogStatus::Expected);
}

void UDataManager::LoadAtlasDataFromScribe(UAtlas* Master, TArray<UAtlas*> AtlasList)
{
	Log.Write("Loading Atlas Data from Scribe", ELogStatus::Expected);
	ActiveAtlases.Empty();

	int L = AtlasList.Num();

	for (int i = 0; i < L; i++)
	{
		UAtlas* Atlas = AtlasList[i];
		Atlas->DataFromJson(&Log);
		ActiveAtlases.Add(Atlas->UID,Atlas);
	}

	MasterAtlas = Master;

	bAtlasDataLoaded = true;

	Log.Write("Loading AtlasData From ScribeComplete", ELogStatus::Expected);
}

FString UDataManager::GetDataDir()
{
	return Global::DataManager->AtlasDir;
}


bool UDataManager::TryAtlas(UAtlas*& Output, int UN)
{
	if (Atlases.Contains(UN))
	{
		Output = Atlases.FindRef(UN);
		return true;
	}

	return false;
}

TArray<UAtlas*> UDataManager::GetAllAtlas()
{
	TArray<UAtlas*> Arr;

	for (const TPair<int, UAtlas*>& pair : Global::DataManager->Atlases)
	{
		Arr.Add(pair.Value);
	}

	return Arr;
}

TArray<UForm_F*> UDataManager::Query(FString Query, UFormType* ParentType, TArray<UFormType*> FormTypeFilters)
{
	TArray<UForm_F*> ValidData;
	for (const TPair<int, UAtlas*>& pair : ActiveAtlases)
	{
		pair.Value->Query(&ValidData, Query, ParentType, FormTypeFilters);
	}

	return ValidData;
}

UFormType* UDataManager::GetFormType(int FormType)
{
	return FormTypes.FindRef(FormType);
}

TArray<UFormType*> UDataManager::GetAllFormTypes()
{
	TArray<UFormType*> Arr;
	for (const TPair<int, UFormType*>& pair : FormTypes)
	{
		Arr.Add(pair.Value);
	}

	return Arr;
}

void UDataManager::SaveMaster()
{
	MasterAtlas->Save();
}