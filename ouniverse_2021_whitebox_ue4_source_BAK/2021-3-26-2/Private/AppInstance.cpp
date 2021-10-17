// Fill out your copyright notice in the Description page of Project Settings.


#include "AppInstance.h"

namespace Global
{
	UAppInstance* AppInstance;
}


void UAppInstance::Init()
{
	Global::AppInstance = this;
}

UAppInstance* UAppInstance::GetAppInstance() 
{
	return Global::AppInstance; 
}