// Fill out your copyright notice in the Description page of Project Settings.


#include "Cam.h"
#include "Camera/CameraComponent.h"
#include "Math/UnrealMathUtility.h"
#include "APC.h"


// Sets default values
ACam::ACam()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	// Create a follow camera
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ACam::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACam::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACam::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}