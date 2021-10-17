// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UserManager.generated.h"

class UUser;


UCLASS()
class APP_API UUserManager : public UObject
{
	GENERATED_BODY()

	static const FName SYS;

public:

	UUserManager();

	static UUserManager* Get();

	void Init();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TArray<UUser*> Users;

	void LoadAllUsersOnDisk();

};
