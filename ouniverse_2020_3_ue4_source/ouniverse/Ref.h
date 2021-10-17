// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Ref.generated.h"

class DataD;

UCLASS()
class OUNIVERSE_API ARef : public AActor
{
	GENERATED_BODY()


	UPROPERTY(EditAnywhere)
	int PackKey;
	UPROPERTY(EditAnywhere)
	int DataKey;

public:	

	DataD* TestString;

	// Sets default values for this actor's properties
	ARef();
	
	void PostLoad() override;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
