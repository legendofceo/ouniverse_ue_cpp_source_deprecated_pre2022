// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/StreamableManager.h"
#include "AppStream.generated.h"

UCLASS()
class APP_API UAppStream : public UObject
{
	GENERATED_BODY()

public:


	static const FName SYS;

	UAppStream();

	static UAppStream* Get();

	FStreamableManager StreamableManager;

	void Stream(FSoftObjectPath TargetToStream, FStreamableDelegate DelegateToCall);
	void Stream(TArray<FSoftObjectPath> TargetsToStream, FStreamableDelegate DelegateToCall);
};
