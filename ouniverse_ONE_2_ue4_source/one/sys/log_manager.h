// Fill out your copyright notice in the Description page of Project Settings.


#pragma once

#include "base.h"
#include "log.h"
#include "log_manager.generated.h"

UCLASS()
class ALogManager : public ABase
{

	GENERATED_BODY()

public:

	ALogManager() {};

	UPROPERTY(VisibleAnywhere)
	TMap<FString, FLogger> Logs;

	bool TryAddLog(FLogger& Output,FString Name);
	bool TryGetLog(FLogger& Output, FString Name);

	static ALogManager* Create(AActor* WorldActor);
	static ALogManager* Get();

	
};