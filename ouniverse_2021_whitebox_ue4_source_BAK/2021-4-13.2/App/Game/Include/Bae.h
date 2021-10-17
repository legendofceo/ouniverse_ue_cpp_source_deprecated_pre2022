// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Bae.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class APP_API UBae : public UActorComponent
{
	GENERATED_BODY()

public:

public:
	// Sets default values for this component's properties
	UBae();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

};
