// Fill out your copyright notice in the Description page of Project Settings.


#include "Chassis.h"
#include "AppStream.h"
#include "Log.h"
#include "ActraEx.h"
#include "Components/SkeletalMeshComponent.h"

const FName UChassis::SYS = "Chassis";


void UChassis::Init(AActraEx* InActra)
{
	ActraEx = InActra;
}

void UChassis::SetSkeletalMeshComponent(USkeletalMeshComponent* InSMC)
{
	SMC = InSMC;
	SMC->SetSkeletalMesh(SkeletalMesh);
}

USkeletalMeshComponent* UChassis::AddDynamicSkeletalMeshComponent()
{
	USkeletalMeshComponent* NewMesh = NewObject<USkeletalMeshComponent>(ActraEx, USkeletalMeshComponent::StaticClass());
	NewMesh->SetupAttachment(SMC);
	NewMesh->RegisterComponent();
	DynamicSkeletalMeshComponents.Add(NewMesh);
	return NewMesh;
}
