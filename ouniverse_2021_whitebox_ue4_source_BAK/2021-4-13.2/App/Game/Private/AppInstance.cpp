// Fill out your copyright notice in the Description page of Project Settings.


#include "AppInstance.h"
#include "GameData.h"
#include "Task.h"
#include "SoftServe.h"

namespace Global
{
	UApp* App;
}


UApp::UApp()
{
	Global::App = this;
}

UApp* UApp::Get()
{
	return Global::App;
}

void UApp::GetApp(UApp*& App)
{
	App = Global::App; 
}

void UApp::Boot()
{
	LogMaster = FLoggerMaster();
	FLoggerMaster::SetMasterLogger(&LogMaster);
	Log.W("Boot()").UE();

	if (!bInitialized)
	{

		Log.W("App is not initialized. Initializing now").UE();


		SoftServe = NewObject<USoftServe>(this, USoftServe::StaticClass());
		SoftServe->Add(GameDataClass);

		if (SoftServe->HasNull())
		{
			Log.W("A SoftServe class is null. (AppInstance)").Type(TCRIT).DM().UE();
			return;
		}

		SoftServe->OnComplete.AddDynamic(this, &UApp::BootSS);
		SoftServe->Stream();
	}
	else
	{
		Log.W("App is already Initialized").Type(TWARN).UE();
	}
}

void UApp::BootSS(USoftServe* SS)
{
	Log.W("BootSS()").UE();
	GameData = NewObject<UGameData>(this, GameDataClass.Get());
	GameData->OnInitComplete.AddDynamic(this,&UApp::SubInitComplete);
	InitTasks.Add(GameData);
	GameData->Init();
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, FString::FromInt(GameData->GetResourceSizeBytes(EResourceSizeMode::Exclusive)));
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, FString::FromInt(GameData->GetResourceSizeBytes(EResourceSizeMode::EstimatedTotal)));
}

void UApp::SubInitComplete(UObject* SubObject)
{
	GameData->OnInitComplete.RemoveDynamic(this, &UApp::SubInitComplete);
	InitTasks.Remove(SubObject);

	if (InitTasks.Num() == 0)
	{
		bInitialized = true;
		Log.W("SubInit Complete. Fire OnInitComplete Delegate").UE();
		
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