// Fill out your copyright notice in the Description page of Project Settings.


#include "App/ControlRelay.h"


bool UControlRelayInterface::OnStroke(const FFKey& InCommand)
{
	return IControllable::Execute_OnCommand(Controllable_.GetObject(), InCommand); // Message is of type FString
}

bool UControlRelayInterface::OnAxis(const FFAxis& InAxis)
{
	return IControllable::Execute_OnAxis(Controllable_.GetObject(), InAxis); // Message is of type FString
}

void UControlRelayInterface::SetRelay(UObject* InRelay)
{
	Controllable_.SetObject(InRelay); // BroadcastListener is of type TScriptInterface
	Controllable_.SetInterface(Cast<IControllable>(InRelay));
}