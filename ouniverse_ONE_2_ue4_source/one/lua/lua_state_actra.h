// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "lua_state_global.h"
#include "lua_state_actra.generated.h"


UCLASS()
class ULuaStateActra : public ULuaStateGlobal
{
	GENERATED_BODY()
public:

	ULuaStateActra();

	UFUNCTION()
	FLuaValue GetName();

};