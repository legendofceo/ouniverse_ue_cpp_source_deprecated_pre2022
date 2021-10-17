// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Addon.generated.h"

class AActra;
class UWearable;

UCLASS(Blueprintable)
class ETREIAAPP_API AAddon : public AActor
{
	GENERATED_BODY()
	
public:	
	AAddon();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	AActra* Actra;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UWearable* Wearable;
	
	void Setup(AActra* InActra, UWearable* InWearable);

	UFUNCTION(BlueprintImplementableEvent)
	void DoAddonDisplay();

};