// Fill out your copyright notice in the Description page of Project Settings.



#include "Cam.h"
#include "Camera/CameraComponent.h"

ACam::ACam()
{
	CameraComponent_ = CreateDefaultSubobject<UCameraComponent>(TEXT("Cam"));
	CameraComponent_->SetupAttachment(RootComponent);
	CameraComponent_->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, 0.0f), FRotator(0.0f, 0.0f, 0.0f));
}


void ACam::SetFOV(float InFOV)
{
	CameraComponent_->SetFieldOfView(InFOV);
}

void ACam::SetGoal(UCameraComponent* InCam)
{
	CameraComponent_->AttachToComponent(InCam, FAttachmentTransformRules::KeepRelativeTransform);
	CameraComponent_->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, 0.0f), FRotator(0.0f, 0.0f, 0.0f));

}