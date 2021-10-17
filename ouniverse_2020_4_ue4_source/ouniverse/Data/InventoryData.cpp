// Fill out your copyright notice in the Description page of Project Settings.



#include "InventoryData.h"


UBackpack::UBackpack()
{

}

UBackpack* UBackpack::Create()
{
	UBackpack* Neu = NewObject<UBackpack>();
	return Neu;
}


UInventory* UInventory::Create()
{
	UInventory* Neu = NewObject<UInventory>();
	return Neu;
}

UInventory::UInventory()
{

}

FInventoryQD UInventory::QuickData() 
{
	return FInventoryQD();
}

FString UInventory::JsonData() 
{ 
	return ""; 
}

void UInventory::Load(FInventoryQD InMD)
{

}