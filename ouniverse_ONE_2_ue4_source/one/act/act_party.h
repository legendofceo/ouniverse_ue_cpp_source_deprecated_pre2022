// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "act_party.generated.h"

class UStaticMeshComponent;
class UComMarker;

UCLASS()
class AActParty : public AActor
{
	GENERATED_BODY()

public:

	AActParty();

	virtual void BeginPlay() override;

	//virtual void PostLoad() override;

	//virtual void OnConstruction(const FTransform& Transform);

	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	UComMarker* Origin;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UComMarker* P1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UComMarker* P2;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UComMarker* P3;

	UFUNCTION(BlueprintCallable)
	void Assume();

};