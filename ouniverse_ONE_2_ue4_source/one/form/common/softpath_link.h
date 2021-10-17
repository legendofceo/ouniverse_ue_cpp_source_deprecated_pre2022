// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../../type/array.h"
#include "../../type/json.h"
#include "../form_f.h"
#include "../../sys/atlas.h"
#include "../../sys/data_manager.h"
#include "softpath_link.generated.h"


USTRUCT(BlueprintType)
struct FSoftPathLink
{
	GENERATED_BODY()

public:


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bEmpty;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bLinked;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Atlas;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Path;

};

template <typename Object>
struct SoftObjectPathLinkS
{

public:
	
	SoftObjectPathLinkS() {};

	TSoftObjectPtr<Object> Link;

	bool bEmpty = false;
	bool bLinked = false;
	int Atlas;
	FString Path;

	FSoftPathLink CreateStruct()
	{
		FSoftPathLink S = FSoftPathLink();
		S.bEmpty = bEmpty;
		S.bLinked = bLinked;
		S.Atlas = Atlas;
		S.Path = Path;
		return S;
	}

	FString ToString()
	{
		return Link.ToString();
	}

	bool TryPath()
	{
		Link = TSoftObjectPtr<Object>(FSoftObjectPath("atlas//"+FString::FromInt(Atlas)+"//" + Path));
		bLinked = true;
		return true;
	}

	bool FromJson(Form_F* InData, JsonS* J, const char* Key)
	{

		if (J->TryString(Path))
		{
			//If only a string is provided then the data address is within the containing datapack.

			Atlas = InData->Atlas->UID;
			return TryPath();
		}
		else if (J->IsArray())
		{
			//If an array is present the data address is within an external datapack.

			if (J->At(0).TryInt(Atlas))
			{
				UAtlas* OutAtlas = nullptr;

				if (UDataManager::Get()->TryAtlas(OutAtlas, Atlas))
				{
					if (J->At(1).TryString(Path))
					{
						return TryPath();
					}
				}

			}
		}

		bEmpty = true;
		return false;
	}

	bool TryEntry(JsonS* PathJ, UAtlas* Pack)
	{
		UDataManager* DataManager = UDataManager::Get();

		FString OutPath;
		Form_F* OutData;
		int OutUN;

		if (PathJ->TryString(OutPath))
		{
			//If only a string is provided then the data address is within the containing datapack.
			Link = TSoftObjectPtr<Object>(FSoftObjectPath(Pack->GetContentPath()+OutPath));
			return true;

		}
		else
		{
			//If an array is present the data address is within an external datapack.

			if (PathJ->At(0).TryInt(OutUN))
			{
				UAtlas* OutAtlas = nullptr;

				if (DataManager->TryAtlas(OutAtlas, OutUN))
				{
					if (PathJ->At(1).TryString(OutPath))
					{
						if (Pack->TryData(OutData, OutUN))
						{
							Link = TSoftObjectPtr<Object>(FSoftObjectPath(OutAtlas->GetContentPath() + OutPath));
							return true;
						}
					}
				}
			}

		}

		return false;
	}

};