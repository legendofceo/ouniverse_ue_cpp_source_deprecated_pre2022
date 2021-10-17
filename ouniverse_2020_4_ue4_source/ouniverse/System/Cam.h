// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Cam.generated.h"


class UCameraComponent;

UCLASS()
class OUNIVERSE_API ACam : public AActor
{
	GENERATED_BODY()

public:

	ACam();

	void SetFOV(float InFOV);

	UPROPERTY(Category = CameraActor, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* CameraComponent_;

	void SetGoal(UCameraComponent* InCam);

};