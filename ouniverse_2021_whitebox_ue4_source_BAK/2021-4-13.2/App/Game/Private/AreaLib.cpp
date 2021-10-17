// Fill out your copyright notice in the Description page of Project Settings.


#include "AreaLib.h"
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
	Log.W("PostSS()").UE();
	PostSSBP();
	Complete();
}

void UAreaLib::AreaInitialized(UArea* InArea)
{
	AreaInitQue.Remove(InArea);
	InArea->OnInitComplete.RemoveDynamic(this, &UAreaLib::AreaInitialized);

	Log.W("Area Initialized: " + InArea->ID.ToString() + " | Remaining: " + FString::FromInt(AreaInitQue.Num()) + " / " + FString::FromInt(TotalAreas)).UE();
	if (AreaInitQue.Num() == 0)
	{
		Complete();
	}
}

void UAreaLib::PostInit()
{
	Log.W("PostInit() Calling Init on all Areas.").UE();

	TotalAreas = 0;

	for (const TPair<int, UArea* >& Pair : Areas)
	{
		UArea* Val = Pair.Value;
		AreaInitQue.Add(Val);
		Val->OnInitComplete.AddDynamic(this, &UAreaLib::AreaInitialized);
		Val->Init(&Log);
		TotalAreas++;
	}

	Log.W("Initializing Areas, Total: " + FString::FromInt(TotalAreas)).UE();
	
}

void UAreaLib::AreaSCP(TSoftClassPtr<UArea>SCP, TSoftClassPtr<UArea>& R)
{
	R = SCP;
}

void UAreaLib::RegArea(TSoftClassPtr<UArea> AreaClass, FString MarshalKey, UArea*& Param)
{
	UArea* NewArea = NewObject<UArea>(this, AreaClass.Get());
	Log.W("Registering Area: " + FString::FromInt(NewArea->Key)).UE();
	Marshal.AddObject(MarshalKey, &NewArea->Marshal);
	Param = NewArea;
	Areas.Add(NewArea->Key, NewArea);
}