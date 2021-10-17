// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Info.h"
#include "Pro.generated.h"

class USceneComponent;

UCLASS(hidecategories = (Transform, Cooking, Actor, LOD))
class APP_API APro : public AInfo
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APro();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	USceneComponent* Root;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


};
