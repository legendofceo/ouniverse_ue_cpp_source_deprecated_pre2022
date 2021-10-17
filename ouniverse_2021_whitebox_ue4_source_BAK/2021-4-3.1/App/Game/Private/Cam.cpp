// Fill out your copyright notice in the Description page of Project Settings.


#include "Cam.h"
#include "Camera/CameraComponent.h"

// Sets default values
ACam::ACam()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	// Create a follow camera
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComponent->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ACam::BeginPlay()
{
	Super::BeginPlay();

}

void ACam::SetTarget(UCameraComponent* CamTarget)
{
	CameraComponent->AttachToComponent(CamTarget, FAttachmentTransformRules::KeepRelativeTransform);
	CameraComponent->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, 0.0f), FRotator(0.0f, 0.0f, 0.0f));
}