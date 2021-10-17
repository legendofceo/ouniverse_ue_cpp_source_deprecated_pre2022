// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "base.h"
#include "file_manager.generated.h"

UCLASS()
class AFileManager : public ABase
{
	GENERATED_BODY()

public:


	AFileManager() {};
	static AFileManager* Create(AActor* WorldActor);
	static AFileManager* Get();

	void Constructor();

	UPROPERTY(Category = "0-Details", VisibleAnywhere, BlueprintReadOnly)
	FString MyDocuments;

	UPROPERTY(Category = "0-Details", VisibleAnywhere, BlueprintReadOnly)
	FString WritableFolder;

	UPROPERTY(Category = "0-Details", VisibleAnywhere, BlueprintReadOnly)
	FString UserFolder;

	static FString GetUserFolder();
	static FString GetWritableFolder();

	static TArray<FString> GetAllFoldersInDir(FString Directory);
	static TArray<FString> GetAllFilesInDir(FString Directory);

	static bool DoesFileExist(FString Path);

	static FString NormalizeDir(FString Path);

	static bool TryFileToString(FString& Output, FString Path);

	static bool EnsureDirTree(FString Path);
};