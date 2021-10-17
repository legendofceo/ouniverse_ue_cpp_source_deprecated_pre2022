// Fill out your copyright notice in the Description page of Project Settings.



#include "user.h"
#include "../type/json.h"
#include "user_manager.h"
#include "file_manager.h"
#include "log.h"


AUser::AUser()
{
	bValid = false;
	bActive = false;
}

AUser* AUser::Create(AActor* WorldActor)
{
	AUser* N = WorldActor->GetWorld()->SpawnActor<AUser>(FVector(0.0f, 0.0f, 0.0f), FRotator(0.0f, 0.0f, 0.0f));
	N->Constructor();
	return N;
}

void AUser::Constructor()
{

}

void AUser::Activate()
{
	bActive = true;
	FString LoadoutDocPath = AbsolutePath + "." + AUserManager::UserLoadoutFileEXT;

	bool bDocExists = AFileManager::DoesFileExist(LoadoutDocPath);

	if (bDocExists)
	{
		FString FileData;
		FFileHelper::LoadFileToString(FileData, *DocPath);

		if (!JsonS::IsValidJson(FileData))
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "NOT VALID");
			bValid = false;
		}
		else
		{
			JsonS J;
			J.Parse(FileData);

			//U = J.Int("u");
			LastLoadout = 1;
			J.TryInt(LastLoadout, "last_loadout");
			JsonS Loadouts = JsonS();

			if (J.TryArray(Loadouts, "loadouts"))
			{
				
			}
		}
	}
}

void AUser::Deactivate()
{
	bActive = false;
}

void AUser::FromJsonDocument(int32 NumericUID,FLogger* Log)
{

	
	StringUID = FString::FromInt(NumericUID);
	UID = NumericUID;
	AbsolutePath = AFileManager::NormalizeDir(AFileManager::GetUserFolder() + StringUID + "//");
	DocPath = AbsolutePath + "." + AUserManager::UserFileEXT;

	bool bDocExists = AFileManager::DoesFileExist(DocPath);

	if (bDocExists)
	{
		FString FileData;
		FFileHelper::LoadFileToString(FileData, *DocPath);

		if (!JsonS::IsValidJson(FileData))
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "NOT VALID");
			bValid = false;
			return;
		}
		else
		{
			JsonS J;
			J.Parse(FileData);

			//U = J.Int("u");
			if (!J.TryString(ID, "id"))
			{
				Log->Write("User Rejected: "+StringUID+". Missing ID field in Json.", ELogStatus::Notice);
				bValid = false;
				return;
			}
			if (!J.TryInt(Icon, "icon"))
			{
				Icon = 1;
			}
		}

		bValid = true;
	}
}


bool AUser::IsValid()
{
	return true;
}

FText AUser::PrintID()
{
	return FText::FromString(ID);
}

int32 AUser::GetUID()
{
	return UID;
}


bool AUser::IsActive()
{
	return bActive;
}