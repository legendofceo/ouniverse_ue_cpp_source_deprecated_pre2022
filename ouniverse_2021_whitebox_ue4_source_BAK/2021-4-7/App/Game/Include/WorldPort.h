// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "WorldPort.generated.h"

class APlayerPort;

UCLASS()
class APP_API UWorldPort : public UActorComponent
{
	GENERATED_BODY()

public:

public:
	// Sets default values for this component's properties
	UWorldPort();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	APlayerPort* PlayerPort;

	void Plug(APlayerPort* InPlayerPort) {};

};