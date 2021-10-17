// Fill out your copyright notice in the Description page of Project Settings.

#include "com_marker.h"
#include "Components/StaticMeshComponent.h"


UComMarker::UComMarker()
{

#if WITH_EDITOR

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Marker"));
	Mesh->SetupAttachment(this);

#endif

}