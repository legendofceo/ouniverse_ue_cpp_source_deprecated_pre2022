// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ObjectPlus.h"
#include "Delegate.h"
#include "Area.generated.h"

class ULevelStreamingDynamic;
class ALevelScriptActor;

UCLASS(Abstract, BlueprintType, Blueprintable)
class APP_API UArea : public UObjectPlus
{
	GENERATED_BODY()


	static const FName SYS;

public:

	UPROPERTY(EditAnywhere)
	FName KeyID;

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "#Load"))
	void LoadBP();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "#LoadLevel"))
	void LoadLevel(TSoftObjectPtr<UWorld> Level, const FDelDynamicObject& Callback);

	UFUNCTION()
	void LevelLoaded();

	FDelDynamicObject OnLoadLevelComplete;

	ULevelStreamingDynamic* LevelStreamingDynamic;

	UPROPERTY()
	ALevelScriptActor* LevelScriptActor;
	
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "#StartLevel", DefaultToSelf = "Area"))
	void StartLevel(UArea* Area);

};