// Fill out your copyright notice in the Description page of Project Settings.


#include "AppState.h"
#include "AppMem.h"
#include "AppMemInitializer.h"

namespace Global
{
	AAppState* AppState;
}

AAppState::AAppState()
{
	Global::AppState = this;
}


AAppState* AAppState::GetAppState()
{
	return Global::AppState;
}