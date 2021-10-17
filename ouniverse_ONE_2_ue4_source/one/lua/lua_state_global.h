// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LuaState.h"
#include "lua_state_global.generated.h"

/**
 *
 */
UCLASS()
class ULuaStateGlobal : public ULuaState
{
	GENERATED_BODY()
public:
	ULuaStateGlobal();

	UFUNCTION()
		FLuaValue GetPlayerPawnLocation();

	UFUNCTION()
		FLuaValue GetSimpleString();

	UFUNCTION()
	FLuaValue GetTime();

	UFUNCTION()
	FLuaValue GetDay();

	UFUNCTION()
	FLuaValue GetMonth();

	UFUNCTION()
	FLuaValue GetYear();

};