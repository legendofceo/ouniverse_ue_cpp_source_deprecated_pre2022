// Fill out your copyright notice in the Description page of Project Settings.


#include "AppInstance.h"
#include "Log.h"
#include "GameData.h"
#include "Task.h"
#include "SoftServe.h"
#include "Misc/CString.h"

const FName UApp::SYS = "APP";

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


void UApp::CreateLog(const UObject* WorldContextObject)
{
	if (IsValid(WorldContextObject->GetWorld()->GetAuthGameMode()))
	{
		Log = NewObject<ULogger>(this, ULogger::StaticClass());

		LOG.S(SYS).W("CreateLog()");
	}
}

void UApp::SetupGameData(const UObject* WorldContextObject)
{

	LOG.S(SYS).W("SetupGameData()");

	SoftServe = NewObject<USoftServe>(this, USoftServe::StaticClass());
	SoftServe->Add(GameDataClass);

	if (SoftServe->HasNull())
	{
		LOG.S(SYS).T(TCRIT).W("A SoftServe class is null").DebugM();
		return;
	}

	SoftServe->OnComplete.AddDynamic(this, &UApp::SetupGameData_SS);
	SoftServe->Stream();

}

void UApp::SetupGameData_SS(USoftServe* SS)
{
	LOG.S(SYS).W("SetupGameData_SS()");
	GameData = NewObject<UGameData>(this, GameDataClass.Get());
	GameData->OnInitComplete.AddDynamic(this,&UApp::SetupGameDataComplete);
	InitTasks.Add(GameData);
	GameData->Init();
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, FString::FromInt(GameData->GetResourceSizeBytes(EResourceSizeMode::Exclusive)));
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, FString::FromInt(GameData->GetResourceSizeBytes(EResourceSizeMode::EstimatedTotal)));
}

void UApp::SetupGameDataComplete(UObject* SubObject)
{
	GameData->OnInitComplete.RemoveDynamic(this, &UApp::SetupGameDataComplete);
	InitTasks.Remove(SubObject);

	if (InitTasks.Num() == 0)
	{
		LOG.S(SYS).W("SubInit Complete. Fire OnInitComplete Delegate");
		
		OnSetupGameDataComplete.Broadcast();
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