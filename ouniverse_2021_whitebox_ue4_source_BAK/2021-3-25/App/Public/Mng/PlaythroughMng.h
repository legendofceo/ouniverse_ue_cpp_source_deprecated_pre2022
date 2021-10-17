// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PlaythroughMng.generated.h"

class AAppMem;

UCLASS(Abstract, BlueprintType, Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class APP_API UPlaythroughMng : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPlaythroughMng();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void Init(AAppMem* InAppMem);
	AAppMem* AppMem;

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "@NewGame"))
	void NewGameBP();

	void NewGame();

	void Start() {};
};