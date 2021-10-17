// Fill out your copyright notice in the Description page of Project Settings.


#pragma once

#include "base.h"
#include "log.h"
#include "user_manager.generated.h"


class AUser;

UCLASS()
class AUserManager : public ABase
{

	GENERATED_BODY()

public:

	static AUserManager* Create(AActor* WorldActor);
	static AUserManager* Get();

	UFUNCTION(Category = "UserManager", BlueprintCallable)
	static AUserManager* GetUserManager();

	AUserManager();
	void Constructor();
	
	void LoadUsers();

	static FString UserFileEXT;
	static FString UserLoadoutFileEXT;

	UPROPERTY(Category = "0 Details", VisibleAnywhere, BlueprintReadOnly)
	bool bUsersLoaded;

	UPROPERTY(Category = "0 Details", VisibleAnywhere)
	AUser* ActiveUser;

	TMap<int32, AUser*> Users;

	UPROPERTY(Category = "0 Details", VisibleAnywhere)
	int UserNum;

	UPROPERTY(Category = "0 Details", VisibleAnywhere)
	int UserFoldersScanned;

	UPROPERTY(Category = "0 Details", VisibleAnywhere)
	int UserFoldersAccepted;

	UPROPERTY(Category = "0 Details", VisibleAnywhere)
	FLogger Log;

	bool HasActiveUser();
	
	bool HasAnyUser();

	bool TryUser(AUser*& Output, int32 InUID);

	void AutoUser(int32 InUID);

	void SetActiveUser(AUser* InUser);

	UFUNCTION(BlueprintCallable)
	AUser* GetActiveUser();

	UFUNCTION(BlueprintCallable)
	TArray<AUser*> GetUsers();

};