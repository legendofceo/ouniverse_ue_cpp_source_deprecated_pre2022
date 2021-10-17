// Fill out your copyright notice in the Description page of Project Settings.


#include "LuaScript.h"
#include "LuaBridge.h"
#include <string>
#include "AppInstance.h"


SLuaScript::SLuaScript()
{

	SLuaState();

	luabridge::getGlobalNamespace(L)
		.beginClass<UApp>("app")
		.addProperty("version", &UApp::Version)
		.endClass();

	luabridge::push(L, UApp::Get());
	lua_setglobal(L, "app");

	/**
	luabridge::getGlobalNamespace(L)
		.beginClass<UAreaActive>("area_active")
		.addFunction("set_map", &UAreaActive::LUA_SetMap)
		.endClass();

	luabridge::getGlobalNamespace(L)
		.beginClass<UMapActive>("map_active")
		.endClass();
	*/
}

void SLuaScript::RunCMD(FString CMD)
{
	int r = luaL_dostring(L, TCHAR_TO_UTF8(*CMD));

	//const char* lua_script = TCHAR_TO_UTF8(*CMD);

	//int load_stat = luaL_loadbuffer(L, lua_script, strlen(lua_script), lua_script);
	//lua_pcall(L, 0, 0, 0);
}

SLuaArea::SLuaArea()
{
	SLuaScript();

	//luabridge::push(L, AreaActive);
	//lua_setglobal(L, "this");

}

void SLuaArea::ChooseDestination(UAreaActive* AreaActive, FName Address, FName ExtraData)
{
	lua_getglobal(L, "activearea_script_request_destination");
	if (lua_isfunction(L, -1))
	{
		//lua_pushstring(L, TCHAR_TO_UTF8(*Address.ToString()));
		//lua_pushstring(L, TCHAR_TO_UTF8(*ExtraData.ToString()));
		luabridge::push(L, AreaActive);
		lua_pcall(L, 1, 0, 0);

		//return lua_tostring(L, -1);
	}
}

SLuaMap::SLuaMap()
{
	SLuaScript();
}


void SLuaMap::LevelFullyLoaded(UMapActive* MapActive)
{
	lua_getglobal(L, "mapactive_script_level_fully_loaded");
	if (lua_isfunction(L, -1))
	{
		luabridge::push(L, MapActive);
		lua_pcall(L, 1, 0, 0);
	}
}