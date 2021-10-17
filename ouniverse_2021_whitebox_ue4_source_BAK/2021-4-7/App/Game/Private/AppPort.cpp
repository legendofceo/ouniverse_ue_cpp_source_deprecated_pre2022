// Fill out your copyright notice in the Description page of Project Settings.


#include "AppPort.h"


UAppPort::UAppPort()
{
	PrimaryComponentTick.bCanEverTick = true;
}


void UAppPort::BeginPlay()
{
	Super::BeginPlay();
}

void UAppPort::Plug(AAppController* InAppController)
{
	AppController = InAppController;
}

bool UAppPort::IsEmpty()
{
	if (AppController == NULL)
	{
		return true;
	}

	else
	{
		return false;
	}
}