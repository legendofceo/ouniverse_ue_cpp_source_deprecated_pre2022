// Fill out your copyright notice in the Description page of Project Settings.


#include "ico_manager.h"
#include "../ui/ico.h"

namespace Global
{
	UIcoManager* IcoManager;
}


UIcoManager* UIcoManager::Create(TSoftClassPtr<UIcoManager> SoftClass, UObject* WorldCTX)
{
	Global::IcoManager = NewObject<UIcoManager>(WorldCTX, SoftClass.LoadSynchronous());
	return Global::IcoManager;
}

UIcoManager* UIcoManager::Get()
{
	return Global::IcoManager;
}

TSoftClassPtr<UIco_U> UIcoManager::FindOrDefault(int32 InID)
{

	if (Lib.Contains(InID))
	{
		return Lib.FindRef(InID);
	}
	else
	{
		return DefaultIco;
	}
}