// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MemMng.generated.h"

class AAppMem;

UCLASS(Abstract, BlueprintType, Blueprintable, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class APP_API UMemMng : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UMemMng();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:

	void Init(AAppMem* InAppMem);

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	AAppMem* AppMem;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void SetupNewGame();
};
