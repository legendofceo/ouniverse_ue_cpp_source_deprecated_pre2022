// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "base.h"
#include "log.h"
#include "deep_memory.generated.h"



UCLASS()
class ADeepMemory : public ABase
{
	GENERATED_BODY()

public:
	
	ADeepMemory();

	static ADeepMemory* Create(AActor* WorldActor);
	static ADeepMemory* Get();

	UPROPERTY(Category = "0 Details", VisibleAnywhere, BlueprintReadOnly)
	int LastUserUID;

	UPROPERTY(Category = "0 Details", VisibleAnywhere, BlueprintReadOnly)
	FLogger Log;

	UPROPERTY(Category = "0 Details", VisibleAnywhere, BlueprintReadOnly)
	FString Path;

	void Constructor();
	void Load();

};