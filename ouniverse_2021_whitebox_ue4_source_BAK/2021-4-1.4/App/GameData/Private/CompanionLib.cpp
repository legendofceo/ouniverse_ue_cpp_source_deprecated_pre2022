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
	Log.Write(AAUTH,LNORM,VNONE,1,0, "PostSS()");
	PostSSBP();
	Complete();
}

void UCompanionLib::PostInit()
{
	Log.Write(AAUTH, LNORM, VNONE, 1, 0, "Post Init. (Currently Does Nothing here)");
	Complete();
}

void UCompanionLib::CompanionSCP(TSoftClassPtr<UCompanion>SCP, TSoftClassPtr<UCompanion>& R)
{
	R = SCP;
}
void UCompanionLib::RegCompanion(TSoftClassPtr<UCompanion> CompanionClass, FString MarshalKey, UCompanion*& Param)
{
	UCompanion* NewCompanion = NewObject<UCompanion>(this, CompanionClass.Get());
	Log.Write(AAUTH,LNORM,VNONE,1,0, "RegisteringCompanion: " + FString::FromInt(NewCompanion->Key));
	Marshal.AddObject(MarshalKey, &NewCompanion->Marshal);
	Param = NewCompanion;
	Companions.Add(NewCompanion->Key,NewCompanion);
}