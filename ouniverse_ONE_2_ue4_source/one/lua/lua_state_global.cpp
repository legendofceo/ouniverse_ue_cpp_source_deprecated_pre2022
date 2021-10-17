// Fill out your copyright notice in the Description page of Project Settings.

#include "lua_state_global.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "GameFramework/Pawn.h"

ULuaStateGlobal::ULuaStateGlobal()
{
	Table.Add("simple_string", FLuaValue("Test string"));
	Table.Add("get_player_location", FLuaValue::Function(GET_FUNCTION_NAME_CHECKED(ULuaStateGlobal, GetPlayerPawnLocation)));
	Table.Add("get_simple_string", FLuaValue::Function(GET_FUNCTION_NAME_CHECKED(ULuaStateGlobal, GetSimpleString)));

	Table.Add("get_time", FLuaValue::Function(GET_FUNCTION_NAME_CHECKED(ULuaStateGlobal, GetTime)));
	Table.Add("get_date", FLuaValue::Function(GET_FUNCTION_NAME_CHECKED(ULuaStateGlobal, GetDay)));
	Table.Add("get_month", FLuaValue::Function(GET_FUNCTION_NAME_CHECKED(ULuaStateGlobal, GetMonth)));
	Table.Add("get_year", FLuaValue::Function(GET_FUNCTION_NAME_CHECKED(ULuaStateGlobal, GetYear)));

}

FLuaValue ULuaStateGlobal::GetPlayerPawnLocation()
{
	FVector Location = UGameplayStatics::GetPlayerPawn(GetWorld(), 0)->GetActorLocation();
	FLuaValue NewTable = CreateLuaTable();
	NewTable.SetField("x", FLuaValue(Location.X));
	NewTable.SetField("y", FLuaValue(Location.X));
	NewTable.SetField("z", FLuaValue(Location.X));

	return NewTable;
}

FLuaValue ULuaStateGlobal::GetSimpleString()
{
	return FLuaValue("Hello World");
}

FLuaValue ULuaStateGlobal::GetTime()
{
	return FLuaValue("5:20");
}

FLuaValue ULuaStateGlobal::GetDay()
{
	return FLuaValue("Sunday");
}

FLuaValue ULuaStateGlobal::GetMonth()
{
	return FLuaValue("October");
}

FLuaValue ULuaStateGlobal::GetYear()
{
	return FLuaValue("2020");
}