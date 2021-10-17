// Fill out your copyright notice in the Description page of Project Settings.

#include "file_manager.h"
#include "Misc/Paths.h"


namespace Global
{
	AFileManager* FileManager;
}


AFileManager* AFileManager::Create(AActor* WorldActor)
{
	Global::FileManager = WorldActor->GetWorld()->SpawnActor<AFileManager>(FVector(0.0f, 0.0f, 0.0f), FRotator(0.0f, 0.0f, 0.0f));
	Global::FileManager->Constructor();
	return Global::FileManager;
}

AFileManager* AFileManager::Get()
{
	return Global::FileManager;
}


void AFileManager::Constructor()
{
	IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();

	MyDocuments = FPlatformProcess::UserDir();

	WritableFolder = MyDocuments + "One//";
	FPaths::NormalizeDirectoryName(WritableFolder);
	PlatformFile.CreateDirectoryTree(*WritableFolder);

	UserFolder = WritableFolder + "users//";
	FPaths::NormalizeDirectoryName(UserFolder);
	PlatformFile.CreateDirectoryTree(*UserFolder);
}

FString AFileManager::GetWritableFolder()
{
	return Global::FileManager->WritableFolder;
}

FString AFileManager::GetUserFolder()
{
	return Global::FileManager->UserFolder;
}

FString AFileManager::NormalizeDir(FString Path)
{
	FPaths::NormalizeDirectoryName(Path);
	return Path;
}

TArray<FString> AFileManager::GetAllFoldersInDir(FString Directory)
{
	TArray<FString> Folders;
	FString Path = Directory + "*";
	FPaths::NormalizeDirectoryName(Path);
	IFileManager::Get().FindFiles(Folders, *Path, false, true);

	return Folders;
}

TArray<FString> AFileManager::GetAllFilesInDir(FString Directory)
{
	TArray<FString> Files;
	FString Path = Directory + "*";
	FPaths::NormalizeDirectoryName(Path);
	IFileManager::Get().FindFiles(Files, *Path, true, false);

	return Files;
}

bool AFileManager::DoesFileExist(FString Path)
{
	return IFileManager::Get().FileExists(*Path);
}

bool AFileManager::TryFileToString(FString& Output, FString Path)
{
	return FFileHelper::LoadFileToString(Output, *Path);;
}


bool AFileManager::EnsureDirTree(FString Path)
{
	IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();
	return PlatformFile.CreateDirectoryTree(*Path);
}