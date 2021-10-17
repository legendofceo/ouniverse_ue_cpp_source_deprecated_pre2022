// Fill out your copyright notice in the Description page of Project Settings.


#include "System.h"


USystem::USystem()
{

}

void USystem::SetInitCallback(FDelBasicObject OnInitComplete)
{
	InitCompleteCB = OnInitComplete;
}

void USystem::Init()
{
	bInit = false;
	InitComplete();
}

void USystem::InitComplete()
{
	bInit = true;
	InitCompleteCB.ExecuteIfBound(this);
}