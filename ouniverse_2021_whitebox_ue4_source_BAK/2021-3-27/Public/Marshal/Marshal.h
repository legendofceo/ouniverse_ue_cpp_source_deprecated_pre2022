// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Marshal.generated.h"


class MarshalObjectC;

USTRUCT(BlueprintType)
struct FMarshalNew
{
	GENERATED_BODY()

public:

	MarshalObjectC* M;

	FMarshalNew();

};