// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"
#include "LevelMap.generated.h"


UCLASS(Blueprintable,BlueprintType)
class APP_API ALevelZone : public ALevelScriptActor
{
	GENERATED_BODY()

	static const FName SYS;

public:

	void BeginPlay() override;

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "#Start"))
	void Start();


	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "#BeginStart"))
	void BeginStartBP();

};
