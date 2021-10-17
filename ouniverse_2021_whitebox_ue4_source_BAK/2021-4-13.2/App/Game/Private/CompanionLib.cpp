// Fill out your copyright notice in the Description page of Project Settings.


#include "CompanionLib.h"
#include "Engine/StreamableManager.h"
#include "Engine/AssetManager.h"
#include "Companion.h"

namespace Manager
{
	UCompanionLib* Companion = NULL;
}

UCompanionLib* UCompanionLib::Get()
{
	return Manager::Companion;
}

void UCompanionLib::GetCompanionMngBP(UCompanionLib*& CompanionMng)
{
	CompanionMng = Manager::Companion;
}

void UCompanionLib::Init()
{
	Manager::Companion = this;
	ULib::Init();
}

void UCompanionLib::PostSS()
{
	Log.W("PostSS()").UE();
	PostSSBP();
	Complete();
}

void UCompanionLib::PostInit()
{
	Log.W("Post Init. (Currently Does Nothing here)").UE();
	Complete();
}

void UCompanionLib::CompanionSCP(TSoftClassPtr<UCompanion>SCP, TSoftClassPtr<UCompanion>& R)
{
	R = SCP;
}
void UCompanionLib::RegCompanion(TSoftClassPtr<UCompanion> CompanionClass, FString MarshalKey, UCompanion*& Param)
{
	UCompanion* NewCompanion = NewObject<UCompanion>(this, CompanionClass.Get());
	Log.W("RegisteringCompanion: " + FString::FromInt(NewCompanion->Key)).UE();
	Marshal.AddObject(MarshalKey, &NewCompanion->Marshal);
	Param = NewCompanion;
	Companions.Add(NewCompanion->Key,NewCompanion);
}