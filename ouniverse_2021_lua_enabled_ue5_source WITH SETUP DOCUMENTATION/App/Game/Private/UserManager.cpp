// Fill out your copyright notice in the Description page of Project Settings.


#include "UserManager.h"
#include "Log.h"
#include "Misc/Paths.h"
#include "User.h"
#include "AppInstance.h"

const FName UUserManager::SYS = "UserManager";

namespace System
{
	UUserManager* UserManager = nullptr;
}


UUserManager::UUserManager()
{

}

void UUserManager::Init()
{
	LOG.S(SYS).W("Init()");
	System::UserManager = this;
}

UUserManager* UUserManager::Get()
{
	return System::UserManager;
}

void UUserManager::LoadAllUsersOnDisk()
{
	//FString UserDir = AFileManager::GetUserFolder();
	//TArray<FString> Folders = AFileManager::GetAllFoldersInDir(UserDir);

	LOG.S(SYS).W("LoadAllUsersOnDisk()");

	//TArray<FString> Folders;
	//FString Path = UsersDir + "*";


	int MaxUsers = 5;

	for (int i = 0; i < MaxUsers; i++)
	{
		UUser* User = NewObject<UUser>(this, UUser::StaticClass());
		User->Init(i);
		Users.Add(User);
	}

	bool bAnyUserExists = false;

	for (UUser* User : Users)
	{
		if (User->bExists)
		{
			LOG.S(SYS).W("A user exists");
			bAnyUserExists = true;
			break;
		}
	}

	if (!bAnyUserExists)
	{
		LOG.S(SYS).W("No Users exists, adding new User");
		Users[0]->New();
	}
	else
	{
		LOG.S(SYS).W("Existing users found");
	}

	UUser* HighestPrioUser = nullptr;

	for (UUser* User : Users)
	{
		if (User->bExists)
		{
			if (!HighestPrioUser)
			{
				HighestPrioUser = User;
			}
			else
			{
				if (User->LastLogin > HighestPrioUser->LastLogin)
				{
					HighestPrioUser = User;
				}
			}
			break;
		}
	}

	UApp::Get()->User = HighestPrioUser;
}