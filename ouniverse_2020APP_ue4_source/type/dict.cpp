// Fill out your copyright notice in the Description page of Project Settings.

#include "dict.h"
#include "json.h"
#include "../sys/file_manager.h"

FDict::FDict()
{

}


bool FDict::Load(FString InPath, const char* InKey, const char* InVal)
{

	Path = InPath;
	bool bDocExists = AFileManager::DoesFileExist(Path);

	if (bDocExists)
	{
		FString FileData;
		FFileHelper::LoadFileToString(FileData, *Path);

		JsonS J = JsonS();
		if (!JsonS::IsValidJson(FileData))
		{
			return false;
		}
		else
		{
			J.Parse(FileData);
			int L = J.Num();
			for (int i = 0; i < L; i++)
			{
				FName Key = FName(*(J[i].String(InKey)));
				FString Val = J[i].String(InVal);
				Dictionary.Add(Key, Val);
			}
		}
	}
	
	return true;
}

bool FDict::Try(FString& Output, FName InKey)
{
	if (Dictionary.Contains(InKey))
	{
		Output = Dictionary.FindRef(InKey);
		return true;
	}

	return false;
}

void FDict::Clear()
{
	Dictionary.Empty();
}
