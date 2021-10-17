// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/PlayerCameraManager.h"
#include "AppCam.generated.h"

/**
 *
 */

class UCameraComponent;



UCLASS()
class APP_API UCamTweenPartyShift : public UObject
{
	GENERATED_BODY()

public:
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool bComplete;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	AAppCam* CM;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FVector StartPos;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FRotator StartRot;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float StartFOV;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float TimeFactor;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float CurTime = 0.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UCameraComponent* Target;

	void Setup(AAppCam* InAAppCam, FTViewTarget OutVT, UCameraComponent* InTarget, float TotalTime);

	void Tween(FTViewTarget& OutVT, float DeltaTime);
};


UCLASS()
class APP_API AAppCam : public APlayerCameraManager
{
	GENERATED_BODY()

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		FTViewTarget LastFrameVT;

	UPROPERTY(EditDefaultsOnly, Category = Curve)
		UCurveFloat* CurveCameraShift;

	void EndTween();

	virtual void UpdateViewTargetInternal(FTViewTarget& OutVT, float DeltaTime) override;

	void ForceCameraTarget(UCameraComponent* InTarget);

	void RunTween(UCamTweenPartyShift* InActiveTween);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		bool bIsTweening = false;


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UCamTweenPartyShift* ActiveTween;


	UCameraComponent* Target;

	UCameraComponent* TweenTarget;
};
