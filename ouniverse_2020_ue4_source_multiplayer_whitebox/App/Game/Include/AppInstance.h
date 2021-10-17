// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Delegate.h"
#include "AppInstance.generated.h"

class ULogger;
class UGameData;
class USoftServe;
class UUser;
class UTask;

UCLASS()
class APP_API UApp : public UGameInstance
{
	GENERATED_BODY()

public:

	static const FName SYS;

	UApp();

	static UApp* Get();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	ULogger* Log;

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = ":App"))
	static void GetApp(UApp*& App);



	UFUNCTION(BlueprintCallable, meta = (DisplayName = "#CreateLog", WorldContext = "WorldContextObject"))
	void CreateLog(const UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "#SetupData", WorldContext = "WorldContextObject"))
	void SetupGameData(const UObject* WorldContextObject);

	UFUNCTION()
	void SetupGameData_SS(USoftServe* SS);

	UFUNCTION()
	void SetupGameDataComplete(UObject* SubObject);

	UPROPERTY(BlueprintAssignable)
	FDelegate OnSetupGameDataComplete;



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


	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSet<UTask*> GlobalTasks;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSet<UTask*> LocalTasks;

	void RegLocalTask(UTask* Task);

	UFUNCTION()
	void ClearLocalTask(UTask* Task);

};
