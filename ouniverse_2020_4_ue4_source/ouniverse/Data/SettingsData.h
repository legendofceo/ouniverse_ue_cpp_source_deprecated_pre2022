// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SettingsData.generated.h"


UCLASS()
class OUNIVERSE_API USettings : public UObject
{
	GENERATED_BODY()

public:

	USettings();

	static USettings* Create();
	
//GlobalSettings:
	

//SaveSettings:

	bool MouseInvertY;
	bool MouseInvertX;

	FString JsonData();
};