// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Origin.generated.h"


class UEditorMarker;


UCLASS()
class OUNIVERSE_API AOriginParty : public AActor
{
	GENERATED_BODY()

		
		

public:

	AOriginParty();

	//virtual void BeginPlay() override;

	//virtual void PostLoad() override;

	//virtual void OnConstruction(const FTransform& Transform);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UEditorMarker* EdMarker0;

};