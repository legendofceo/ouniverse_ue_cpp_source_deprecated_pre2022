// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../../type/json.h"


struct LuaScriptDataS
{

public:

	LuaScriptDataS();
	LuaScriptDataS(JsonS* J);

	int UID;
	bool bLoaded = true;
	FString Content;

};

struct LuaScriptStackS
{

public:

	LuaScriptStackS() {};

	LuaScriptStackS(JsonS* J);

	ArrayC<LuaScriptDataS> Stack;
};