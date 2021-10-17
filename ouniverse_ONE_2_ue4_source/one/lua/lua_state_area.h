// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "lua_state_global.h"
#include "lua_state_area.generated.h"

/**
 *
 */
UCLASS()
class ULuaStateArea : public ULuaStateGlobal
{
	GENERATED_BODY()
public:

	ULuaStateArea();

	UFUNCTION()
	FLuaValue GetName();

};