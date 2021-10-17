// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AppPort.generated.h"


class AAppController;

UCLASS()
class APP_API UAppPort : public UActorComponent
{
	GENERATED_BODY()

public:

public:
	// Sets default values for this component's properties
	UAppPort();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;


public:

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	AAppController* AppController = NULL;
	
	//APlayerPort* PlayerPort;


	void Plug(AAppController* InAppController);

	bool IsEmpty();
};