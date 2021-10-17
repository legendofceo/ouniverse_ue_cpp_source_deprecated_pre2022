// Fill out your copyright notice in the Description page of Project Settings.

#include "lua_state_area.h"


ULuaStateArea::ULuaStateArea()
{
	LuaFilename = "scripts/area.lua";
	Table.Add("get_name", FLuaValue::Function(GET_FUNCTION_NAME_CHECKED(ULuaStateArea, GetName)));
}


FLuaValue ULuaStateArea::GetName()
{
	return FLuaValue("Fionerrrrrrrrrr");
}