// Fill out your copyright notice in the Description page of Project Settings.


#include "Story.h"


void AStory::IsAvailable_Implementation(EYesNo& Branch)
{
	Branch = EYesNo::Yes;
}

void AStory::SetAreaAddressOverride(FAreaAddress AreaAddress)
{
	AreaAddressOverride = AreaAddress;
}

bool AStory::HasAreaAddressOverride()
{
	if (AreaAddressOverride.IsValid())
	{
		return true;
	}
	else
	{
		return false;
	}
}

FAreaAddress AStory::GetAreaAddressOverride()
{
	return AreaAddressOverride;
}

void AStory::ClearAreaAddressOverride()
{
	AreaAddressOverride.Invalidate();
}