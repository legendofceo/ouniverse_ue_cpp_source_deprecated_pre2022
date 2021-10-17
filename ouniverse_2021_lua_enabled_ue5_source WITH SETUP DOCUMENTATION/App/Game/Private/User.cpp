// Fill out your copyright notice in the Description page of Project Settings.


#include "User.h"
#include "Log.h"
#include "UserManager.h"
#include "AppInstance.h"
#include "Json+.h"

const FName UUser::SYS = "User";

void UUser::Init(int Index)
{
	FolderIndex = Index;
	bExists = false;

	FolderIndexWritten = FString::FromInt(Index+1);

	DocPath = UApp::Get()->AppDataFolder+"u"+ FolderIndexWritten +".etreia";

	bool bDoesUserDocExist = IFileManager::Get().FileExists(*DocPath);
	
	if(!bDoesUserDocExist)
	{
		LOG.S(SYS).I(*FolderIndexWritten).T(TCRIT).W("Path does not exist: "+ DocPath);
		SaveDoc();//This will create an empty doc despite the name
		return;
	}

	FString Doc;
	FFileHelper::LoadFileToString(Doc, *DocPath);;

	if (!JsonS::IsValidJson(Doc))
	{
		//Potentially should make a backup here in case user fucks up while tinkering.
		LOG.S(SYS).I(*FolderIndexWritten).T(TCRIT).W("Doc is not valid Json, resetting.");
		SaveDoc();//This will create an empty doc despite the name
		return;
	}

	JsonS J = JsonS::Parse(Doc);

	if (J.Has("pending"))
	{
		LOG.S(SYS).I(*FolderIndexWritten).T(TCRIT).W("Doc is awaiting a user.");
		return;
	}

}

void UUser::New()
{
	Name = "DefaultUser";
	FolderID = 149;
	bExists = true;
	LastLogin = FDateTime().Now();
	SaveDoc();
}

void UUser::SaveDoc()
{
	if (!bExists)
	{
		JsonS J = JsonS();
		J.Add("pending", 1);
		J.Serialize();
		FFileHelper::SaveStringToFile(J.Serialize(), *DocPath);
	}
	else
	{
		JsonS J = JsonS();
		J.Add("name", Name);
		J.Add("folder", FolderID);
		J.Add("lastseen", LastLogin.ToUnixTimestamp());
		J.Serialize();
		FFileHelper::SaveStringToFile(J.Serialize(), *DocPath);
	}
}


void UUser::GetNameBP(FText& RName)
{
	RName = FText::FromString(Name);
}
void UUser::GetScoreBP(FText& RScore)
{
	RScore = FText::FromString(FString::FromInt(Score));
}