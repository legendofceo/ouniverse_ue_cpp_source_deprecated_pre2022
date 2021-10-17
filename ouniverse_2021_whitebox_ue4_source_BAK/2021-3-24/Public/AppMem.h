// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Info.h"
#include "Mem.h"
#include "../Enum/EBranch.h"
#include "AppMem.generated.h"

/**
 * 
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FAppMemDelegate);

class UWorld;
class UStory;
class UCompanion;
class UAppMemInitializer;
class UStoryPrimary;

UENUM(BlueprintType)
enum EMemFlagTypes
{
	EMemFlagTypesMap UMETA(DisplayName = "Map"),
	EMemFlagTypesBool UMETA(DisplayName = "Bool"),
	EMemFlagTypesByte   UMETA(DisplayName = "Byte"),
	EMemFlagTypesInt   UMETA(DisplayName = "Int"),
	EMemFlagTypesString   UMETA(DisplayName = "String"),
	EMemFlagTypesFloat   UMETA(DisplayName = "Float"),
};


UCLASS(Abstract)
class APP_API AAppMem : public AInfo
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, BlueprintPure)
	static AAppMem* GetAppMem();

	AAppMem();
	~AAppMem();

	virtual void BeginPlay();

//MemObjects

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FMemState Mem;

	FMemState* GetMemPtr();

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TMap<FName, TSoftObjectPtr<UWorld>> Maps;

	TSoftObjectPtr<UWorld> GetMap(FName Key);


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TMap<int, UStory*> Stories;

	UFUNCTION(BlueprintCallable)
	void AddStory(UStory* Story);

	UStory* GetStory(int StoryKey);

	UFUNCTION(Category="AppMem", BlueprintCallable, BlueprintPure, meta = (DisplayName = "#Story"))
	static void GetStoryBP(int Key, UStory*& Story);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TMap<int, UCompanion*> Companions;

	UFUNCTION(BlueprintCallable)
	void AddCompanion(UCompanion* Companion);

	UCompanion* GetCompanion(int CompanionKey);

	UFUNCTION(Category = "AppMem", BlueprintCallable, BlueprintPure, meta = (DisplayName = "#Companion"))
	static void GetCompanionBP(int Key, UCompanion*& Companion);

	UFUNCTION(Category = "AppMem", BlueprintCallable, meta = (DisplayName = "#GetBool", ExpandEnumAsExecs = Execs))
	static void GetBoolBP(FName Key, EYesNo& Execs);

	UFUNCTION(Category = "AppMem", BlueprintCallable, meta = (DisplayName = "#SetBool"))
	static void SetBoolBP(FName Key, bool Value);

	UFUNCTION(Category = "AppMem", BlueprintCallable, meta = (DisplayName = "#SetBoolTrue"))
	static void SetBoolTrueBP(FName Key);

	UFUNCTION(Category = "AppMem", BlueprintCallable, meta = (DisplayName = "#SetBoolFalse"))
	static void SetBoolFalseBP(FName Key);

	static void FailFlagLookup(FName Key, TEnumAsByte<EMemFlagTypes> FlagType);

//Initialization

	UPROPERTY(BlueprintAssignable)
	FAppMemDelegate OnInitComplete;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSoftClassPtr<UAppMemInitializer> AppMemInitializerClass = NULL;

	UPROPERTY()
	UAppMemInitializer* ADI;

	UFUNCTION()
	void BeginInit();

	UFUNCTION()
	void GetInitializerLL();

	UFUNCTION()
	void InitializeLL();

	void ConcludeMemOverwrite();

	void FailInit();

	bool InitStory(int Key, TSoftClassPtr<UStory> StoryClass,UStory*& Story);
	bool InitCompanion(int Key, TSoftClassPtr<UCompanion> CompanionClass, UStory* Story, UCompanion*& Companion);

	
//ActiveStory

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UStory* ActiveStory;

	UFUNCTION(BlueprintCallable)
	void ChangeStory(UStory* Story);

};

USTRUCT()
struct APP_API FItemMem
{
	GENERATED_BODY()

public:

	UPROPERTY()
	FName Key;

	UPROPERTY()
	int Quantity;

	UPROPERTY()
	bool bEquipped;

	UPROPERTY()
	FName Slot;
	
	UPROPERTY()
	FName bLost;

	UPROPERTY()
	FName Transmog;

	UPROPERTY()
	FString Rename;

};