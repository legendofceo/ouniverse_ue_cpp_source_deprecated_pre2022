// Fill out your copyright notice in the Description page of Project Settings.


#include "GameData.h"
#include "Log.h"
#include "SoftServe.h"
#include "AreaLib.h"
#include "StoryLib.h"
#include "CompanionLib.h"
#include "Playthrough.h"


const FName UGameData::SYS = "GAMEDATA";

UGameData::UGameData()
{

}



void UGameData::Init()
{
	LOG.S(SYS).W("Init()");

	SoftServe = NewObject<USoftServe>(this, USoftServe::StaticClass());
	SoftServe->Add(PlaythroughClass);
	SoftServe->Add(AreaLibClass);
	SoftServe->Add(CompanionLibClass);
	SoftServe->Add(StoryLibClass);

	if (SoftServe->HasNull())
	{
		LOG.S(SYS).T(TCRIT).W("A SoftServe class is null. (GameData)").DebugM();
		return;
	}

	SoftServe->OnComplete.AddDynamic(this, &UGameData::InitSS);
	SoftServe->Stream();
}



void UGameData::InitSS(USoftServe* SS)
{
	LOG.S(SYS).W("InitSS()");

	SoftServe->OnComplete.RemoveDynamic(this, &UGameData::InitSS);

	Playthrough = NewObject<UPlaythrough>(this, PlaythroughClass.Get());
	Playthrough->OnInitComplete.AddDynamic(this, &UGameData::SubInitComplete);
	InitTasks.Add(Playthrough);
	

	AreaLib = NewObject<UAreaLib>(this, AreaLibClass.Get());
	AreaLib->SetSYS("AREALIB");
	Libs.Add(AreaLib);

	CompanionLib = NewObject<UCompanionLib>(this, CompanionLibClass.Get());
	CompanionLib->SetSYS("COMPANIONLIB");
	Libs.Add(CompanionLib);

	StoryLib = NewObject<UStoryLib>(this, StoryLibClass.Get());
	StoryLib->SetSYS("STORYLIB");
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

	LOG.S(SYS).W("SubInitComplete() Report Received. Remaining: "+InitTasks.Num());

	if (InitTasks.Num() == 0)
	{
		LOG.S(SYS).W("SubInitComplete(). Received All Reports: Starting PostInit");

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
	LOG.S(SYS).W("Received PostInit Report. Remaining: " + InitTasks.Num());
	InitTasks.Remove(Object);

	if (InitTasks.Num() == 0)
	{
		LOG.S(SYS).W("PostInit Complete. InitPast2 Complete. Boot Complete");
		OnInitComplete.Broadcast(this);
	}
}