// Fill out your copyright notice in the Description page of Project Settings.


#include "AppSettings.h"


const FName UAppSettings::SYS = "AppSettings";

namespace App
{
	UAppSettings* Config = nullptr;
}

UAppSettings::UAppSettings()
{
	App::Config = this;
}

UAppSettings* UAppSettings::Get()
{
	return App::Config;
}

float UAppSettings::InvertCamY(float Power, InputDevice Device)
{
	if (Device == InputDevice::Mouse)
	{
		return Power * -1;
	}
	else if (Device == InputDevice::Gamepad)
	{
		return Power * -1;
	}

	return Power;
}