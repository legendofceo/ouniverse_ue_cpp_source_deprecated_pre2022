// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PartyPort.generated.h"

class APlayerPort;

UCLASS()
class APP_API UPartyPort : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UPartyPort();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	APlayerPort* PlayerPort;	
	
	void Plug(APlayerPort* InPlayerPort) {};

};