// Fill out your copyright notice in the Description page of Project Settings.


#include "Equipable.h"
#include "Actra.h"
#include "Body.h"
#include "Addon.h"









void UEquipable::Setup(AActra* InActra)
{
	Actra = InActra;
}

void UWearable::Setup(AActra* InActra)
{
	Super::Setup(InActra);
	Body = Actra->Body;
}

void UWearableHuman::Setup(AActra* InActra)
{
	Super::Setup(InActra);
	BodyHuman = Cast<UBodyHuman>(Actra->Body);
}

USkeletalMeshComponent* UWearable::AttachSkeletonMeshToBody()
{
	Mesh = NewObject<USkeletalMeshComponent>(Actra, USkeletalMeshComponent::StaticClass());
	Mesh->RegisterComponent();
	Mesh->AttachToComponent(Body->MasterMesh, FAttachmentTransformRules::SnapToTargetIncludingScale);
	return Mesh;
}