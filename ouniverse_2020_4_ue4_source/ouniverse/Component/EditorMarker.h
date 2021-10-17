// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "EditorMarker.generated.h"


UCLASS()
class OUNIVERSE_API UEditorMarker : public UStaticMeshComponent
{
	GENERATED_BODY()

	

public:

	UEditorMarker();
	void Init();
};