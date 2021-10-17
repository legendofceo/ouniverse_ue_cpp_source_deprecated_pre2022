// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LuaState.h"


class UAreaActive;
class UMapActive;

struct SLuaScript : public SLuaState
{

public:

	SLuaScript();

	void RunCMD(FString CMD);
};

struct SLuaArea : public SLuaScript
{

public:

	SLuaArea();


	void ChooseDestination(UAreaActive* AreaActive, FName Address, FName ExtraData);

};

struct SLuaMap : public SLuaScript
{

public:

	SLuaMap();


	void LevelFullyLoaded(UMapActive* MapActive);

};