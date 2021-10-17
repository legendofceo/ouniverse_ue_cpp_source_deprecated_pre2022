// Fill out your copyright notice in the Description page of Project Settings.

#include "loadout.h"




ULoadout* ULoadout::Create(FString InID)
{
	ULoadout* Lo = NewObject<ULoadout>();
	Lo->ID = InID;
	return Lo;
}


void ULoadout::AddEntry(int32 InUID, FString InName)
{
	Entries.Add(FLoadoutEntry(InUID,InName));
}

void ULoadoutLib::Constructor()
{

}