// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UObject/Object.h"
#include "loadout.generated.h"

USTRUCT(BlueprintType)
struct FLoadoutEntry
{
	GENERATED_BODY()

public:
	FLoadoutEntry() {};

	FLoadoutEntry(int32 InUID, FString InName)
	{
		UID = InUID;
		RememberedName = InName;
	};

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (category = "0 Details", DisplayName = "UID"))
	int32 UID;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (category = "0 Details", DisplayName = "UID"))
	FString RememberedName;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (category = "0 Details", DisplayName = "UID"))
	bool bExists;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (category = "0 Details", DisplayName = "UID"))
	bool bLocked;

};


UCLASS(BlueprintType)
class ULoadout : public UObject
{
	GENERATED_BODY()

public:
	ULoadout() {};
	
	static ULoadout* Create(FString InID);

	UPROPERTY(Category = "0 Details", VisibleAnywhere, BlueprintReadOnly, meta = (DisplayName = "ID"))
	FString ID;

	void AddEntry(int32 InUID, FString InName);

	UPROPERTY(Category = "0 Details", VisibleAnywhere, BlueprintReadOnly, meta = (DisplayName = "ID"))
	TArray<FLoadoutEntry> Entries;	

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (category = "0 Details", DisplayName = "UID"))
	bool bPaused;

};


UCLASS()
class ULoadoutLib : public UObject
{
	GENERATED_BODY()

public:

	ULoadoutLib() {};

	void Constructor();

	UPROPERTY(Category = "0 Details", VisibleAnywhere, BlueprintReadOnly)
	ULoadout* ActiveLoadout;
	UPROPERTY(Category = "0 Details", VisibleAnywhere, BlueprintReadOnly)
	TArray<ULoadout*> Lib;

};