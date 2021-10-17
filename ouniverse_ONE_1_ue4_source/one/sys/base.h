// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "base.generated.h"


UCLASS(BlueprintType)
class ABase : public AActor
{
	GENERATED_BODY()

public:

	UPROPERTY()
	USceneComponent* Dock;

	ABase();

	void Attach(AActor* InChild);

};