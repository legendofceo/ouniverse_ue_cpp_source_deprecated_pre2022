// Fill out your copyright notice in the Description page of Project Settings.


#pragma once

#include "UObject/Object.h"
#include "translation_manager.generated.h"


UCLASS(Blueprintable)
class UTranslationManager : public UObject
{

	GENERATED_BODY()

public:

	UTranslationManager();

	static UTranslationManager* Create();
	static UTranslationManager* Get();
	
	void LoadBaseDictionary(FString FileName);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FString BasePath;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FString OverlayPath;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TMap<FName, FText> BaseDictionary;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TMap<FName, FText> OverlayDictionary;

	FText GetTranslatedText(FName Key);

	UFUNCTION(BlueprintCallable,BlueprintPure)
	static FText Translate(FName Key);

};