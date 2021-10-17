// Fill out your copyright notice in the Description page of Project Settings.

#include "lua_state_actra.h"


ULuaStateActra::ULuaStateActra()
{
	LuaFilename = "scripts/actra.lua";
	Table.Add("get_global_name", FLuaValue::Function(GET_FUNCTION_NAME_CHECKED(ULuaStateActra, GetName)));

}


FLuaValue ULuaStateActra::GetName()
{
	return FLuaValue("Fionerrrrrrrrrr");
}