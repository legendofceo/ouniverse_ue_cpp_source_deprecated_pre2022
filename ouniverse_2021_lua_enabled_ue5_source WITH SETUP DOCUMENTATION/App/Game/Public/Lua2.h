// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ObjectPlus.h"

extern "C"
{
#include "include/lua.h"
#include "include/lauxlib.h"
#include "include/lualib.h"
}

#include "Lua2.generated.h"


UCLASS(BlueprintType,Blueprintable)
class APP_API ULua2 : public UObjectPlus
{
	GENERATED_BODY()

public:


	void Go();

	int LUA_GetGlobal(lua_State* L);

	int Fuck = 4;

};