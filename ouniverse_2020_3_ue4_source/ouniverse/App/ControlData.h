// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "App/ControlEnums.h"
#include "ControlData.generated.h"


USTRUCT(BlueprintType)
struct FFKey
{
	GENERATED_BODY()

		FFKey()
	{
		Command = ECommand::Undefined;
		Source = EControlSource::Undefined;
		Pressed = false;
	}

	FFKey(ECommand InCommand, bool InPressed, EControlSource InSource)
	{
		Command = InCommand;
		Pressed = InPressed;
		Source = InSource;
	}

	UPROPERTY()
		ECommand Command;
	UPROPERTY()
		bool Pressed;
	UPROPERTY()
		EControlSource Source;
};

USTRUCT(BlueprintType)
struct FFAxis
{
	GENERATED_BODY()

		FFAxis()
	{
		Axis = EControlAxis::Undefined;
		Power = 0.0f;
		Source = EControlSource::Undefined;
	}

	FFAxis(EControlAxis InAxis, float InPower, EControlSource InSource)
	{
		Axis = InAxis;
		Power = InPower;
		Source = InSource;
	}

	UPROPERTY()
		EControlAxis Axis;
	UPROPERTY()
		float Power;
	UPROPERTY()
		EControlSource Source;
};