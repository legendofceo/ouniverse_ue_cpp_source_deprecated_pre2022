// Fill out your copyright notice in the Description page of Project Settings.

#include "lua_link.h"


LuaScriptDataS::LuaScriptDataS(JsonS* J)
{

}


LuaScriptStackS::LuaScriptStackS(JsonS* J)
{
	int L = J->Num();

	for (int i = 0; i < L; i++)
	{
		LuaScriptDataS ScriptData = LuaScriptDataS(&J->At(i));
		Stack.Add(ScriptData);
	}
}
