// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractiveManager.h"
#include "Log.h"

#include "InteractiveComponent.h"
#include "PulseManager.h"

#include "AnythingUi.h"
#include "AnythingUiFetch.h"

const FName UInteractiveManager::SYS = "InteractiveManager";

namespace Manager
{
	UInteractiveManager* Interactive = nullptr;
}

UInteractiveManager::UInteractiveManager()
{

}

UInteractiveManager* UInteractiveManager::Get()
{
	return Manager::Interactive;
}

void UInteractiveManager::Init()
{
	Manager::Interactive = this;
	LOG.S(SYS).W("Init()");

	InitComplete();
}

void UInteractiveManager::AddInteractiveComponent(UInteractiveComponent* InteractiveComponent)
{
	InteractiveComponents.Add(InteractiveComponent);
}

void UInteractiveManager::RemoveInteractiveComponent(UInteractiveComponent* InteractiveComponent)
{
	InteractiveComponents.Remove(InteractiveComponent);
}

TArray<UInteractiveComponent*>& UInteractiveManager::GetRelevantInteractiveComponents()
{
	return InteractiveComponents;
}