// Fill out your copyright notice in the Description page of Project Settings.



#include "cam.h"
#include "Runtime/CinematicCamera/Public/CineCameraComponent.h"


ACamView::ACamView()
{
	CameraComponent_ = CreateDefaultSubobject<UCineCameraComponent>(TEXT("Cam"));
	CameraComponent_->SetupAttachment(RootComponent);
	CameraComponent_->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, 0.0f), FRotator(0.0f, 0.0f, 0.0f));
}


void ACamView::SetFOV(float InFOV)
{
	CameraComponent_->SetFieldOfView(InFOV);
}

void ACamView::SetGoal(UCineCameraComponent* InCam)
{
	CameraComponent_->AttachToComponent(InCam, FAttachmentTransformRules::KeepRelativeTransform);
	CameraComponent_->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, 0.0f), FRotator(0.0f, 0.0f, 0.0f));

}

UCam::UCam()
{

}

UCam* UCam::Create(AActor* WorldActor)
{
	UCam* Neu = NewObject<UCam>();
	Neu->Cam_ = WorldActor->GetWorld()->SpawnActor<ACamView>(FVector(0.0f, 0.0f, 0.0f), FRotator(0.0f, 0.0f, 0.0f));
	return Neu;
}






namespace Global
{
	UView* View;
}

UView::UView()
{

}

UView* UView::Create()
{
	UView* Neu = NewObject<UView>();
	Global::View = Neu;
	return Neu;
}

UView* UView::Get()
{
	return Global::View;
}