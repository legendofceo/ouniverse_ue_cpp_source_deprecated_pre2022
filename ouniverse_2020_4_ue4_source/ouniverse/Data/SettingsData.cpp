// Fill out your copyright notice in the Description page of Project Settings.


#include "SettingsData.h"


USettings* USettings::Create()
{
	USettings* Neu = NewObject<USettings>();
	return Neu;
}

USettings::USettings()
{

}

FString USettings::JsonData()
{
	return "";
};

