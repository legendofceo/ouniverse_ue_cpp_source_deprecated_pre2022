// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "base.h"
#include "log.h"
#include "memory_manager.generated.h"



UCLASS()
class AMemoryManager : public ABase
{
	GENERATED_BODY()

public:
	
	AMemoryManager();

	static AMemoryManager* Create(AActor* WorldActor);
	static AMemoryManager* Get();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FLogger Log;

	void Constructor();
};