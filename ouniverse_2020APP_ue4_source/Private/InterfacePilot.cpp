// Fill out your copyright notice in the Description page of Project Settings.


#include "InterfacePilot.h"

// Add default functionality here for any IMyInterface functions that are not pure virtual.

APawn* IInterfacePilot::GetPilotGoal_Implementation()
{
	return nullptr;
}

UCameraComponent* IInterfacePilot::GetPilotCamera_Implementation()
{
	return nullptr;
}

void IInterfacePilot::Engage_Implementation(APC* PC)
{

}

void IInterfacePilot::Disengage_Implementation()
{

}