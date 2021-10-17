// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Data.generated.h"



UCLASS()
class OUNIVERSE_API USave : public UObject
{
	GENERATED_BODY()

public:

	USave();

	static USave* Create();

	int32 Chapter;
	int32 Time;
	int32 LastPlayed;
	int32 Picture;

};

UCLASS()
class OUNIVERSE_API UData : public UObject
{
	GENERATED_BODY()

public:

	UData();

	static UData* Get();
	static UData* Create();
	
	UFUNCTION(BlueprintCallable)
	static void LoadQSB() {};
	UFUNCTION(BlueprintCallable)
	static void LoadQSC() {};
	UFUNCTION(BlueprintCallable)
	static void LoadGame() {};
	UFUNCTION(BlueprintCallable)
	static void NewGame() {};

	TArray<USave*> Saves;

	UFUNCTION(BlueprintCallable)
	static void QuickSaveBattle() {};

	UFUNCTION(BlueprintCallable)
	static void QuickSaveCheckPoint() {};
	
	UFUNCTION(BlueprintCallable)
	static void HardSave() {};

	UFUNCTION(BlueprintCallable)
	static void AutoSave() {};

};