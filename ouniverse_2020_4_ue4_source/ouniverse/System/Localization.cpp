// Fill out your copyright notice in the Description page of Project Settings.

#include "Localization.h"
#include "Reg.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"

namespace GlobalSingleton
{
	ULocalization* gBabel;
}


ULocalization* ULocalization::Get()
{
	return GlobalSingleton::gBabel;
}

ULocalization* ULocalization::Create()
{
	GlobalSingleton::gBabel = NewObject<ULocalization>();
	GlobalSingleton::gBabel->PRE();
	return GlobalSingleton::gBabel;
}


void ULocalization::PRE()
{
	TArray<FString> Line;
	int Split;
	FString Front;
	FString Back;

	FFileHelper::LoadANSITextFileToStrings(*(FPaths::ProjectContentDir()+"/loc/default.babel"), NULL, Line);

	FVector temp;
	for (int i = 0; i < Line.Num(); i++)
	{
		
		FString Dat = Line[i];

		Split = Dat.Find(" ",ESearchCase::IgnoreCase,ESearchDir::FromStart,0);
		
		Front = Dat.Mid(0, Split);
		Back = Dat.RightChop(Split + 1);

		//Line[i].ParseIntoArray(StringArr, TEXT("$"), false);

		Map.Add(FName(*Front), FText::FromString(Back));
	}

}

FText ULocalization::Decode(FName Key)
{
	/**
	if (IsValid(BabelTable))
	{
		FBabelText* Item = BabelTable->FindRow<FBabelText>(Key, "", true);
		if (Item)
		{
			return Item->Val;
		}
		else {
			return FText::FromString("$$$ERROR");
		}
	}
	else
	{
		return FText::FromString(Key.ToString());
	}
	*/

	FText Found;
	if (Map.Contains(Key))
	{
		return *Map.Find(Key);
	}
	else
	{
		return FText::FromString("$$$"+Key.ToString());
	}
}

FText ULocalization::Decipher(FName Code)
{
	return GlobalSingleton::gBabel->Decode(Code);
}