// Fill out your copyright notice in the Description page of Project Settings.

#include "user_manager.h"
#include "file_manager.h"
#include "user.h"

FString AUserManager::UserFileEXT("userinfo");
FString AUserManager::UserLoadoutFileEXT("userloadout");

namespace Global
{
	AUserManager* UserManager;
}

AUserManager::AUserManager()
{
	ActiveUser = nullptr;
	bUsersLoaded = false;
	UserNum = 0;
	UserFoldersScanned = 0;
	UserFoldersAccepted = 0;
}

AUserManager* AUserManager::Create(AActor* WorldActor)
{
	Global::UserManager = WorldActor->GetWorld()->SpawnActor<AUserManager>(FVector(0.0f, 0.0f, 0.0f), FRotator(0.0f, 0.0f, 0.0f));
	Global::UserManager->Constructor();
	return Global::UserManager;
}

AUserManager* AUserManager::Get()
{
	return Global::UserManager;
}

AUserManager* AUserManager::GetUserManager()
{
	return Global::UserManager;
}


void AUserManager::Constructor()
{
	Log = FLogger("Log");
}


void AUserManager::LoadUsers()
{
	FString UserDir = AFileManager::GetUserFolder();
	TArray<FString> Folders = AFileManager::GetAllFoldersInDir(UserDir);

	Log.Write("User Directory: " + UserDir, ELogStatus::Expected);

	int L = Folders.Num();

	for (int i = 0; i < L; i++)
	{
		if (Folders[i].IsNumeric())
		{
			int32 FolderUID = FCString::Atoi(*Folders[i]);
			Log.Write("User Folder: " + FString::FromInt(FolderUID), ELogStatus::Expected);
			UserFoldersScanned++;
			AUser* NewUser = GetWorld()->SpawnActor<AUser>(FVector(0.0f, 0.0f, 0.0f), FRotator(0.0f, 0.0f, 0.0f));
			NewUser->Constructor();
			NewUser->FromJsonDocument(FolderUID,&Log);
			NewUser->SetActorLabel(NewUser->StringUID);

			if (NewUser->IsValid())
			{
				Users.Add(NewUser->UID, NewUser);
				this->Attach(NewUser);
				UserNum++;
			}
			else
			{
				NewUser->Destroy();
			}
		}
	}

	bUsersLoaded = true;
	Log.Write("Loading Users Complete", ELogStatus::Expected);

}


bool AUserManager::HasActiveUser()
{
	if (ActiveUser == nullptr)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool AUserManager::HasAnyUser()
{
	if (UserNum == 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool AUserManager::TryUser(AUser*& Output, int32 InUID)
{
	if (Users.Contains(InUID))
	{
		Output = Users.FindRef(InUID);
		return true;
	}
	return false;
}

void AUserManager::AutoUser(int32 InUID)
{
	AUser* User;
	if(TryUser(User, InUID))
	{
		Log.Write("Last User from memory has been found:" + FString::FromInt(User->UID), ELogStatus::Expected);
		SetActiveUser(User);
	}
	else
	{
		Log.Write("Last User not found:" + FString::FromInt(InUID), ELogStatus::Expected);
		if (UserNum == 1)
		{
			AUser* SingleUser = nullptr;
			for (auto& Elem : Users)
			{
				SingleUser = Elem.Value;
				SetActiveUser(SingleUser);
			}
			Log.Write("Single User Selected:" + SingleUser->StringUID, ELogStatus::Expected);
		}		
	}

}


void AUserManager::SetActiveUser(AUser* InUser)
{
	Log.Write("Setting Active User:" + FString::FromInt(InUser->UID), ELogStatus::Expected);
	if(ActiveUser != nullptr)
	{
		ActiveUser->Deactivate();
	}
	
	ActiveUser = InUser;
	ActiveUser->Activate();

}

AUser* AUserManager::GetActiveUser()
{
	return ActiveUser;
}

TArray<AUser*> AUserManager::GetUsers()
{

	TArray<AUser*> UserArr;

	for (auto& Elem : Users)
	{
		UserArr.Add(Elem.Value);
	}

	return UserArr;
}