// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UObject/Object.h"
#include "UObject/Interface.h"
#include "stroke.generated.h"

UCLASS(BlueprintType)
class UStroke : public UObject
{
	GENERATED_BODY()

public:

	int StrokeID = 0;
	bool bPressed = false;
	bool bHandled = false;

	float TimeHeld = -1.0;

	bool IsHandled()
	{
		return bHandled;
	}
};