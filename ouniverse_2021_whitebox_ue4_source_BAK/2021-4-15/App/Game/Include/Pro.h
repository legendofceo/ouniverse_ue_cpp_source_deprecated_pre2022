// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Pro.generated.h"

class UDataBT;

UCLASS(Abstract, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class APP_API UPro : public UActorComponent
{
	GENERATED_BODY()

public:

public:
	// Sets default values for this component's properties
	UPro();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void BT(UDataBT* Event);

	void AX(UDataBT* Event);

};
