// Fill out your copyright notice in the Description page of Project Settings.


#include "AppInstance.h"
#include "GameData.h"
#include "Task.h"
#include "SoftServe.h"

namespace Global
{
	UApp* AppInstance;
}


void UApp::Init()
{
	Global::AppInstance = this;
}

UApp* UApp::Get()
{
	return Global::AppInstance;
}

void UApp::GetApp(UApp*& App)
{
	App = Global::AppInstance; 
}

void UApp::Boot()
{

	if (!bInitialized)
	{



		SoftServe = NewObject<USoftServe>(this, USoftServe::StaticClass());
		SoftServe->Add(GameDataClass);

		if (SoftServe->HasNull())
		{
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "A Manager SoftClass is not correctly set in AppInstance");
			Log.Write(AAUTH, LCRIT, VNONE, 1, 0, "A Manager SoftClass is not correctly set in AppInstance");
			return;
		}

		SoftServe->OnComplete.AddDynamic(this, &UApp::BootSS);
		SoftServe->Stream();
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "APP IS ALREADY INITIALIZED");
	}
}

void UApp::BootSS(USoftServe* SS)
{
	GameData = NewObject<UGameData>(this, GameDataClass.Get());
	GameData->OnInitComplete.AddDynamic(this,&UApp::SubInitComplete);
	InitTasks.Add(GameData);
	GameData->Init();
}

void UApp::SubInitComplete(UObject* SubObject)
{
	GameData->OnInitComplete.RemoveDynamic(this, &UApp::SubInitComplete);
	InitTasks.Remove(SubObject);

	if (InitTasks.Num() == 0)
	{
		bInitialized = true;

		Log.Write(AAUTH, LNORM, VNONE, 1, 0, "Init Complete");
		OnInitComplete.Broadcast();
	}
}



void UApp::RegLocalTask(UTask* Task)
{
	Task->OnComplete.AddDynamic(this, &UApp::ClearLocalTask);
	LocalTasks.Add(Task);
}

void UApp::ClearLocalTask(UTask* Task)
{
	Task->OnComplete.RemoveDynamic(this, &UApp::ClearLocalTask);
	LocalTasks.Remove(Task);
}