// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Cam.generated.h"

class UCameraComponent;

UCLASS(BlueprintType, Blueprintable)
class APP_API ACam : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACam();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* CameraComponent;

	class UCameraComponent* TargetCamera;

public:

	void SetTarget(UCameraComponent* CamTarget);
};
