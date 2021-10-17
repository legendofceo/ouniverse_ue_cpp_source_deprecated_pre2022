// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UiBase.h"
#include "../System/Input.h"
#include "../System/Flux.h"
#include "UiWin.generated.h"

UCLASS(Abstract, Blueprintable)
class OUNIVERSE_API UUiWin : public UUiBase, public InputC
{

	GENERATED_BODY()

public:


	int BaseID;


};