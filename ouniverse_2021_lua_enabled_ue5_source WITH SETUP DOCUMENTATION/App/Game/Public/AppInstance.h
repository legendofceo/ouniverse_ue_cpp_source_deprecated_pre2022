// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "AppInstance.generated.h"

class UAppStream;

class ULogger;
class UUser;
class UTask;
class UPulseManager;
class AAppMode;
class UAppWorld;
class UAppSettings;

class UUserManager;

UCLASS(Blueprintable,BlueprintType)
class APP_API UApp : public UGameInstance
{
	GENERATED_BODY()


public:

	
	static const FName SYS;

	UApp();

	static UApp* Get();

	int GetVersion();
	UPROPERTY(VisibleAnywhere)
	int Version = 11;


	UPROPERTY(VisibleAnywhere)
	UAppStream* AppStream;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool bDevSkipBrands = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FString AppDataFolder;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FString AppConfigFolder;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FString AppLogFilePath;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	ULogger* Log;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UPulseManager* PulseManager;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UAppSettings* AppSettings;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UAppWorld* AppWorld;

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = ":App"))
	static void GetApp(UApp*& App);

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	AAppMode* AppMode;

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "#Boot", WorldContext = "WorldContextObject"))
	void Boot(const UObject* WorldContextObject);

	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UUserManager* UserManager;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UUser* User;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TSet<UObject*> InitTasks;

	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSet<UTask*> GlobalTasks;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSet<UTask*> LocalTasks;

	void RegLocalTask(UTask* Task);

	UFUNCTION()
	void ClearLocalTask(UTask* Task);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "#Get Active User"))
	static void GetActiveUserBP(UUser*& ActiveUser);

};
