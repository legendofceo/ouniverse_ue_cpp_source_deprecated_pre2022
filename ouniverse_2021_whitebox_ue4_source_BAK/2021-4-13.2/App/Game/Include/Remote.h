// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Remote.generated.h"

class AAppController;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class APP_API URemote : public UActorComponent
{
	GENERATED_BODY()

public:

public:
	// Sets default values for this component's properties
	URemote();

	void Init(AAppController* AP);

	AAppController* AppPlayer;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	bool bEngaged = false;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

};
