// Fill out your copyright notice in the Description page of Project Settings.


#include "Inventory.h"

void FInventory::AddItem(UItemMem* InItem)
{
	Items.Add(InItem);
}