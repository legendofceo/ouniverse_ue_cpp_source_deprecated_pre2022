// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UObject/Object.h"
#include "string_object.generated.h"



UCLASS(Abstract, Blueprintable)
class UStringObject : public UObject
{
	GENERATED_BODY()

public:


	UStringObject() {};

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString String;
};
