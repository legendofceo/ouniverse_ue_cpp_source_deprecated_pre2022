// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CodexPoint.generated.h"


UCLASS()
class OUNIVERSE_API ACodexPoint : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACodexPoint();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
