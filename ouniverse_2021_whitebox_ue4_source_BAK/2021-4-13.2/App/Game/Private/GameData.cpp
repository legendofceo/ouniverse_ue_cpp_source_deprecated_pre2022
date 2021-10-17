// Fill out your copyright notice in the Description page of Project Settings.


#include "GameData.h"
#include "SoftServe.h"
#include "AreaLib.h"
#include "StoryLib.h"
#include "CompanionLib.h"
#include "Playthrough.h"

UGameData::UGameData()
{

}



void UGameData::Init()
{
	Log.W("Init()").UE();

	SoftServe = NewObject<USoftServe>(this, USoftServe::StaticClass());
	SoftServe->Add(PlaythroughClass);
	SoftServe->Add(AreaLibClass);
	SoftServe->Add(CompanionLibClass);
	SoftServe->Add(StoryLibClass);

	if (SoftServe->HasNull())
	{
		Log.W("A SoftServe class is null. (GameData)").Type(TCRIT).DM().UE();
		return;
	}

	SoftServe->OnComplete.AddDynamic(this, &UGameData::InitSS);
	SoftServe->Stream();
}



void UGameData::InitSS(USoftServe* SS)
{
	Log.W("InitSS()").UE();

	SoftServe->OnComplete.RemoveDynamic(this, &UGameData::InitSS);

	Playthrough = NewObject<UPlaythrough>(this, PlaythroughClass.Get());
	Playthrough->OnInitComplete.AddDynamic(this, &UGameData::SubInitComplete);
	InitTasks.Add(Playthrough);
	

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



	Playthrough->Init();

	for (ULib* Lib : Libs)
	{
		Lib->Init();
	}
}



void UGameData::SubInitComplete(UObject* SubObject)
{
	InitTasks.Remove(SubObject);

	Log.W("Received SubInitComplete Report. Remaining: "+InitTasks.Num()).UE();

	if (InitTasks.Num() == 0)
	{
		Log.W("SubInit Complete").UE();

		Log.W("Start PostInit").UE();
		InitTasks.Reset();

		for (ULib* Lib : Libs)
		{
			InitTasks.Add(Lib);
			Lib->OnInitComplete.RemoveDynamic(this, &UGameData::SubInitComplete);
			Lib->OnInitComplete.AddDynamic(this, &UGameData::PostInitComplete);
		}

		InitTasks.Add(Playthrough);
		Playthrough->OnInitComplete.RemoveDynamic(this, &UGameData::SubInitComplete);
		Playthrough->OnInitComplete.AddDynamic(this, &UGameData::PostInitComplete);
		Playthrough->InitPostLib();

		for (ULib* Lib : Libs)
		{
			Lib->PostInit();
		}


	}
}

void UGameData::PostInitComplete(UObject* Object)
{
	Log.W("Received PostInit Report. Remaining: " + InitTasks.Num()).UE();
	InitTasks.Remove(Object);

	if (InitTasks.Num() == 0)
	{
		Log.W("PostInit Complete").UE();
		Log.W("Init Pass 2 completed. Boot Complete").UE();
		OnInitComplete.Broadcast(this);
	}
}