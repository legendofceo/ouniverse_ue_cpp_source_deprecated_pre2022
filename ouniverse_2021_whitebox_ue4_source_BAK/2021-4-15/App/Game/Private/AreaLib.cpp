// Fill out your copyright notice in the Description page of Project Settings.


#include "AreaLib.h"
#include "Log.h"
#include "Engine/StreamableManager.h"
#include "Engine/AssetManager.h"
#include "Area.h"


namespace Lib
{
	UAreaLib* Area = NULL;
}

UAreaLib* UAreaLib::Get()
{
	return Lib::Area;
}

void UAreaLib::GetAreaLibBP(UAreaLib*& AreaLib)
{
	AreaLib = Lib::Area;
}

void UAreaLib::Init()
{
	Lib::Area = this;
	ULib::Init();
}

void UAreaLib::PostSS()
{
	LOG.S(SYS).W("PostSS()");
	PostSSBP();
	Complete();
}

void UAreaLib::AreaInitialized(UArea* InArea)
{
	AreaInitQue.Remove(InArea);
	InArea->OnInitComplete.RemoveDynamic(this, &UAreaLib::AreaInitialized);

	LOG.S(SYS).W("Area Initialized: " + InArea->ID.ToString() + " | Remaining: " + FString::FromInt(AreaInitQue.Num()) + " / " + FString::FromInt(TotalAreas));
	if (AreaInitQue.Num() == 0)
	{
		Complete();
	}
}

void UAreaLib::PostInit()
{
	LOG.S(SYS).W("PostInit() Calling Init on all Areas.");

	TotalAreas = 0;

	for (const TPair<int, UArea* >& Pair : Areas)
	{
		UArea* Val = Pair.Value;
		AreaInitQue.Add(Val);
		Val->OnInitComplete.AddDynamic(this, &UAreaLib::AreaInitialized);
		Val->Init();
		TotalAreas++;
	}

	LOG.S(SYS).W("Initializing Areas, Total: " + FString::FromInt(TotalAreas));
	
}

void UAreaLib::AreaSCP(TSoftClassPtr<UArea>SCP, TSoftClassPtr<UArea>& R)
{
	R = SCP;
}

void UAreaLib::RegArea(TSoftClassPtr<UArea> AreaClass, FString MarshalKey, UArea*& Param)
{
	UArea* NewArea = NewObject<UArea>(this, AreaClass.Get());
	LOG.S(SYS).W("Registering Area: " + FString::FromInt(NewArea->Key));
	Marshal.AddObject(MarshalKey, &NewArea->Marshal);
	Param = NewArea;
	Areas.Add(NewArea->Key, NewArea);
}