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

	Log.Write(AALL, LNORM, VNONE, 1, 0, "Boot()");

	if (!bInitialized)
	{
		Log.Write(AALL, LNORM, VNONE, 1, 0, "App is not initialized. Initializing now");


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
		Log.Write(AALL, LNORM, VNONE, 1, 0, "App is already Initialized");
	}
}

void UApp::BootSS(USoftServe* SS)
{
	Log.Write(AALL, LNORM, VNONE, 1, 0, "BootSS()");
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
		Log.Write(AALL, LNORM, VNONE, 1, 0, "SubInitComplete");
		bInitialized = true;

		Log.Write(AAUTH, LNORM, VNONE, 1, 0, "Init Completed. Fire Delegate");
		
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