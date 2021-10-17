// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UObject/Object.h"
#include "GameFramework/Actor.h"
#include "cam.generated.h"


class UCineCameraComponent;

UCLASS()
class ACamView : public AActor
{
	GENERATED_BODY()

public:

	ACamView();

	void SetFOV(float InFOV);

	UPROPERTY(Category = CameraActor, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UCineCameraComponent* CameraComponent_;

	void SetGoal(UCineCameraComponent* InCam);
};

UCLASS()
class UCam : public UObject
{

	GENERATED_BODY()

public:

	UCam();

	static UCam* Create(AActor* WorldActor);

	ACamView* Cam_;

};

UCLASS()
class UView : public UObject
{

	GENERATED_BODY()

public:

	UView();
	static UView* Create();
	static UView* Get();

	TArray<UCam*> Cams;

};