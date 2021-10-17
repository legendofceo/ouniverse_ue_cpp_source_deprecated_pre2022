// Fill out your copyright notice in the Description page of Project Settings.


#include "Story.h"


void UStory::IsAvailable_Implementation(EYesNo& Branch)
{
	Branch = EYesNo::Yes;
}

void UStory::SetAreaAddressOverride(FAreaAddress AreaAddress)
{
	AreaAddressOverride = AreaAddress;
}

bool UStory::HasAreaAddressOverride()
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

FAreaAddress UStory::GetAreaAddressOverride()
{
	return AreaAddressOverride;
}

void UStory::ClearAreaAddressOverride()
{
	AreaAddressOverride.Invalidate();
}



void UStory::PreStart()
{
	PreStartBP();
}

void UStory::PreStartBP_Implementation()
{

}