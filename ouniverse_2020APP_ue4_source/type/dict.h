// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "dict.generated.h"




USTRUCT(BlueprintType)
struct FDict
{
	GENERATED_BODY()

public:

	FDict();

	UPROPERTY(Category = "0 Details", VisibleAnywhere, BlueprintReadOnly)
	FString Path;

	bool Load(FString InPath, const char* Key="k", const char* Val="v");

	bool Try(FString& Output, FName InKey);

	void Clear();

	UPROPERTY(Category = "0 Details", VisibleAnywhere, BlueprintReadOnly)
	TMap<FName, FString> Dictionary;
};