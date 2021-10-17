// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Log.h"
#include "Delegate.h"
#include "AppInstance.generated.h"


class UGameData;
class USoftServe;
class UUser;
class UTask;

UCLASS()
class APP_API UApp : public UGameInstance
{
	GENERATED_BODY()

public:

	UApp();

	static UApp* Get();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool bInitialized = false;


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FLoggerMaster LogMaster;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FLogger Log;

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = ":App"))
	static void GetApp(UApp*& App);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "#Boot"))
	void Boot();


	UFUNCTION()
	void BootSS(USoftServe* SS);

	UFUNCTION()
	void SubInitComplete(UObject* SubObject);

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	UGameData* GameData;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UUser* User;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TSet<UObject*> InitTasks;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	USoftServe* SoftServe;

	/** SoftClassPointer of the Mem singeleton. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSoftClassPtr<UGameData> GameDataClass = NULL;

	UPROPERTY(BlueprintAssignable)
	FDelegate OnInitComplete;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSet<UTask*> GlobalTasks;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSet<UTask*> LocalTasks;

	void RegLocalTask(UTask* Task);

	UFUNCTION()
	void ClearLocalTask(UTask* Task);

};
