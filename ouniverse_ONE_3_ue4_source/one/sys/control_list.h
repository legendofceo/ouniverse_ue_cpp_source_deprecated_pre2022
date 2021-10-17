// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UObject/Object.h"
#include "control_list.generated.h"


UCLASS(BlueprintType)
class UControlID: public UObject
{
	GENERATED_BODY()

public:

	static int const Advance = 123;
	static int const Escape = 519;
	static int const Accept = 123;

};

UENUM()
enum EStrokeState
{
	StrokeState_Pressed		UMETA(DisplayName = "Pressed"),
	StrokeState_Released	UMETA(DisplayName = "Released"),
};

UENUM()
enum EStrokeKB
{
	StrokeKB_None		UMETA(DisplayName = "None"),
	StrokeKB_Escape		UMETA(DisplayName = "Escape"),
	StrokeKB_Accept		UMETA(DisplayName = "Escape"),
};

UENUM()
enum EStrokePad
{
	StrokePad_None		UMETA(DisplayName = "None"),
	StrokePad_Escape		UMETA(DisplayName = "Escape"),
};

UENUM()
enum EStrokeSpecial
{
	EStrokeSpecial_None			UMETA(DisplayName = "None"),
	EStrokeSpecial_Advance		UMETA(DisplayName = "Advance"),
};