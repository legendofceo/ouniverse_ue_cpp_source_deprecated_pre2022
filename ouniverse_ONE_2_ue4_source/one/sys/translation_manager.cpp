// Fill out your copyright notice in the Description page of Project Settings.

#include "translation_manager.h"
#include "file_manager.h"
#include "../type/json.h"

namespace Global
{
	UTranslationManager* TranslationManager;
}

UTranslationManager::UTranslationManager()
{
	
}

UTranslationManager* UTranslationManager::Create()
{
	Global::TranslationManager = NewObject<UTranslationManager>();
	return Global::TranslationManager;
}

void UTranslationManager::LoadBaseDictionary(FString FileName)
{
	BasePath = FPaths::ProjectContentDir() + "//language//";
	BasePath = AFileManager::NormalizeDir(BasePath);
	BasePath = BasePath + FileName + ".lang";

	FString BaseTranslation;
	AFileManager::TryFileToString(BaseTranslation, BasePath);

	if (!JsonS::IsValidJson(BaseTranslation))
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "LANGUAGE DOCUMENT NOT VALID JSON");
	}
	else
	{
		JsonS J;
		J.Parse(BaseTranslation);
		int L = J.Num();
		
		FString Key;
		FString Val;

		for (int i = 0; i < L; i++)
		{
			J[i].TryString(Key, "k");
			J[i].TryString(Val, "v");
			BaseDictionary.Add(FName(Key), FText::FromString(Val));
		}
	}

}

UTranslationManager* UTranslationManager::Get()
{
	return Global::TranslationManager;
}

FText UTranslationManager::GetTranslatedText(FName Key)
{
	if (OverlayDictionary.Contains(Key))
	{
		return OverlayDictionary.FindRef(Key);
	}
	else if (BaseDictionary.Contains(Key))
	{
		return BaseDictionary.FindRef(Key);
	}
	else
	{
		return FText::FromString(Key.ToString());
	}
}

FText UTranslationManager::Translate(FName Key)
{
	if (IsValid(Global::TranslationManager))
	{
		return Global::TranslationManager->GetTranslatedText(Key);
	}
	return FText::FromString(Key.ToString());
}