// Fill out your copyright notice in the Description page of Project Settings.


#include "base.h"


ABase::ABase()
{
	Dock = CreateDefaultSubobject<USceneComponent>(TEXT("Dock"));
	Dock->SetupAttachment(RootComponent);
}


void ABase::Attach(AActor* InChild)
{
	InChild->AttachToActor(this,FAttachmentTransformRules::KeepRelativeTransform);
}