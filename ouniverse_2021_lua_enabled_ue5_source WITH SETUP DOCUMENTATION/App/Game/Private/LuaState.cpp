// Fill out your copyright notice in the Description page of Project Settings.


#include "LuaState.h"
#include "LuaBridge.h"
#include <string>


SLuaState::SLuaState()
{
	L = luaL_newstate();
	luaL_openlibs(L);

}