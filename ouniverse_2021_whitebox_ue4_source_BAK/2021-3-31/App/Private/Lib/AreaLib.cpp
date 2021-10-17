// Fill out your copyright notice in the Description page of Project Settings.


#include "Lib/AreaLib.h"
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

void UAreaLib::Init()
{
	Lib::Area = this;
	ULib::Init();
}

void UAreaLib::PostAsync()
{
	Log.Write(AAUTH, LNORM, VNONE, 1, 0, "PostAsync()");
	PostAsyncBP();
	Complete();
}

void UAreaLib::AreaSCP(TSoftClassPtr<UArea>SCP, TSoftClassPtr<UArea>& R)
{
	R = SCP;
}
void UAreaLib::RegArea(TSoftClassPtr<UArea> AreaClass, FString MarshalKey, UArea*& Param)
{
	UArea* NewArea = NewObject<UArea>(this, AreaClass.Get());
	Log.Write(AAUTH, LNORM, VNONE, 1, 0, "Registering Area: " + FString::FromInt(NewArea->Key));
	Marshal.AddObject(MarshalKey, &NewArea->Marshal);
	Param = NewArea;
	Areas.Add(NewArea->Key, NewArea);
}