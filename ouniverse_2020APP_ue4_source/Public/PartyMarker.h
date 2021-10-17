// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PartyMarker.generated.h"

UCLASS()
class ETREIAAPP_API APartyMarker : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APartyMarker();

	UFUNCTION(BlueprintCallable)
	void SpawnActiveParty();

	/**
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FTransform PM1;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FTransform PM2;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FTransform PM3;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FTransform PM4;
	*/
};
