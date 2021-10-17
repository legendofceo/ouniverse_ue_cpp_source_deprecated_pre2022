// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/SceneComponent.h"
#include "com_marker.generated.h"

class UStaticMeshComponent;

UCLASS()
class UComMarker : public USceneComponent
{
	GENERATED_BODY()

public:

	UComMarker();

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* Mesh;
};

