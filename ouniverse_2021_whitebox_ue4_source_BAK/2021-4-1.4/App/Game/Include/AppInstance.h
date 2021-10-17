// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "AppInstance.generated.h"


class UGameData;

UCLASS()
class APP_API UApp : public UGameInstance
{
	GENERATED_BODY()

public:
		
	virtual void Init();

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = ":GetApp"))
	static void GetApp(UApp*& App);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "#Boot"))
	void Boot();

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	UGameData* GameData;

};
