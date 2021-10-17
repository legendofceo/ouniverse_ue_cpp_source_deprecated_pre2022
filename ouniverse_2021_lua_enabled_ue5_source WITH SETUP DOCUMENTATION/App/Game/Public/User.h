// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "User.generated.h"


UCLASS()
class APP_API UUser : public UObject
{
	GENERATED_BODY()

	static const FName SYS;

public:

	void Init(int InFolderIndex);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int FolderIndex;


	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	bool bExists = false;

	void New();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FString DocPath;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FString FolderIndexWritten;

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "#Get Name"))
	void GetNameBP(FText& Name);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "#Get Score"))
	void GetScoreBP(FText& Score);
//--------------------------->SAVED DATA

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FString Name;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int Score;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FDateTime LastLogin;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int FolderID;

	void SaveDoc();
};
