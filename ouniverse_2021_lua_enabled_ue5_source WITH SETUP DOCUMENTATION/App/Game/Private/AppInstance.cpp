// Fill out your copyright notice in the Description page of Project Settings.


#include "AppInstance.h"
#include "Log.h"
#include "AppStream.h"
#include "AppWorld.h"
#include "AppSettings.h"
#include "AppMode.h"
#include "Task.h"
#include "Misc/CString.h"

#include "PulseManager.h"
#include "UserManager.h"

#include "Lua2.h"

const FName UApp::SYS = "App";



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

int UApp::GetVersion()
{
	return Version;
}

void UApp::Boot(const UObject* WorldContextObject)
{

	ULua2* Lua2 = NewObject<ULua2>(this, ULua2::StaticClass());
	Lua2->Go();

	Log = NewObject<ULogger>(this, ULogger::StaticClass());
	LOG.S(SYS).W("CreateLog()");
	LOG.S(SYS).W("Begin Boot...");
	LOG.S(SYS).W("Version: " + FString::FromInt(GetVersion()));

	AppStream = NewObject<UAppStream>(this, UAppStream::StaticClass());

	AppSettings = NewObject<UAppSettings>(this, UAppSettings::StaticClass());

	AppWorld = NewObject<UAppWorld>(this, UAppWorld::StaticClass());
	AppWorld->Init(GetWorld(), this);

	AppMode = CastChecked<AAppMode>(GetWorld()->GetAuthGameMode());

	if (!AppMode)
	{
		LOG.S(SYS).T(TCRIT).W("AppMode was not correctly set").DebugM();
		return;
	}

	IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();

	FString MyDocs = FPlatformProcess::UserDir();
	FString AppFolder = MyDocs + "Etreia//";
	FPaths::NormalizeDirectoryName(AppFolder);

	AppDataFolder = AppFolder + "data//";
	FPaths::NormalizeDirectoryName(AppDataFolder);
	PlatformFile.CreateDirectoryTree(*AppDataFolder);

	AppConfigFolder = AppFolder + "config//";
	FPaths::NormalizeDirectoryName(AppConfigFolder);
	PlatformFile.CreateDirectoryTree(*AppConfigFolder);

	AppLogFilePath = AppFolder + "log.etreia";

	UserManager = NewObject<UUserManager>(this, UUserManager::StaticClass());
	UserManager->Init();
	UserManager->LoadAllUsersOnDisk();

	PulseManager = NewObject<UPulseManager>(this, UPulseManager::StaticClass());
	PulseManager->Init();

	AppMode->Boot();
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

void UApp::GetActiveUserBP(UUser*& ActiveUser)
{
	ActiveUser = UApp::Get()->User;

}