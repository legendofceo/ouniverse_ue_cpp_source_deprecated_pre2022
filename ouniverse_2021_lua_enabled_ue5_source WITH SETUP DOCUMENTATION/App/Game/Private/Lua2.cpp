// Fill out your copyright notice in the Description page of Project Settings.


#include "Lua2.h"
#include "LuaBridge.h"
#include <string>

#include "LuaScript.h"


void ULua2::Go()
{

	SLuaScript Script = SLuaScript();

	std::string cmd = "app.version = 80";
	int r = luaL_dostring(Script.L, cmd.c_str());

	//lua_getglobal(Script.L, "a");
	//int Test = (int)lua_tonumber(Script.L, -1);

	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::FromInt(Test));

	/**
	lua_State* L = luaL_newstate();
	luaL_openlibs(L);

	// expose the A class to the Lua scripts
	luabridge::getGlobalNamespace(L)
		.beginClass<ULua2>("test")
		.addProperty("data",&ULua2::Fuck)
		.endClass();

	luabridge::push(L, this);
	lua_setglobal(L, "self");

	std::string cmd = "a = self.data";
	int r = luaL_dostring(L, cmd.c_str());
	lua_getglobal(L, "a");
	int Test = (int)lua_tonumber(L, -1);

	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("HERE"));
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::FromInt(Test));


	cmd = "a = 5 * 5";

	r = luaL_dostring(L, cmd.c_str());

	if (r == LUA_OK)
	{
		lua_getglobal(L, "a");
		if (lua_isnumber(L, -1))
		{
			float a_in_cpp = (float)lua_tonumber(L, -1);
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::SanitizeFloat(a_in_cpp));
		}
	}
	else
	{
		std::string errormsg = lua_tostring(L, -1);
	}


	
	lua_close(L);
	*/
}

int ULua2::LUA_GetGlobal(lua_State* L)
{

	return 1;
}