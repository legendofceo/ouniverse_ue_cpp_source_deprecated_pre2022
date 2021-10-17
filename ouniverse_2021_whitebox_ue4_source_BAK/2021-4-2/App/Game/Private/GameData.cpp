// Fill out your copyright notice in the Description page of Project Settings.


#include "GameData.h"
#include "SoftServe.h"
#include "AreaLib.h"
#include "StoryLib.h"
#include "CompanionLib.h"

UGameData::UGameData()
{

}



void UGameData::Init()
{
	SoftServe = NewObject<USoftServe>(this, USoftServe::StaticClass());
	SoftServe->Add(AreaLibClass);
	SoftServe->Add(CompanionLibClass);
	SoftServe->Add(StoryLibClass);

	if (SoftServe->HasNull())
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "A Lib SoftClass is not correctly set in GameData");
		Log.Write(AAUTH, LCRIT, VNONE, 1, 0, "A Lib SoftClass is not correctly set in GameData");
		return;
	}

	SoftServe->OnComplete.AddDynamic(this, &UGameData::InitSS);
	SoftServe->Stream();
}



void UGameData::InitSS(USoftServe* SS)
{
	SoftServe->OnComplete.RemoveDynamic(this, &UGameData::InitSS);

	AreaLib = NewObject<UAreaLib>(this, AreaLibClass.Get());
	AreaLib->SetID("AreaLib");
	Libs.Add(AreaLib);

	CompanionLib = NewObject<UCompanionLib>(this, CompanionLibClass.Get());
	CompanionLib->SetID("CompanionLib");
	Libs.Add(CompanionLib);

	StoryLib = NewObject<UStoryLib>(this, StoryLibClass.Get());
	StoryLib->SetID("StoryLib");
	Libs.Add(StoryLib);

	for (ULib* Lib : Libs)
	{
		InitTasks.Add(Lib);
		Lib->OnInitComplete.AddDynamic(this, &UGameData::SubInitComplete);
	}

	for (ULib* Lib : Libs)
	{
		Lib->Init();
	}
}



void UGameData::SubInitComplete(UObject* SubObject)
{
	InitTasks.Remove(SubObject);

	if (InitTasks.Num() == 0)
	{
		Log.Write(AAUTH, LNORM, VNONE, 1, 0, "Init Pass 1 completed");
		InitTasks.Reset();

		for (ULib* Lib : Libs)
		{
			InitTasks.Add(Lib);
			Lib->OnInitComplete.RemoveDynamic(this, &UGameData::SubInitComplete);
			Lib->OnInitComplete.AddDynamic(this, &UGameData::PostInitComplete);
		}

		for (ULib* Lib : Libs)
		{
			Lib->PostInit();
		}
	}
}

void UGameData::PostInitComplete(UObject* Object)
{
	InitTasks.Remove(Object);

	if (InitTasks.Num() == 0)
	{
		Log.Write(AAUTH, LNORM, VNONE, 1, 0, "Init Pass 2 completed. Boot Complete");
		OnInitComplete.Broadcast(this);
	}
}