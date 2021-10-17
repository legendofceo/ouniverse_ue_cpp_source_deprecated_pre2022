// Fill out your copyright notice in the Description page of Project Settings.


#include "EquipRack.h"
#include "Viz.h"
#include "ItemMem.h"

void UEquipRack::Init(UVizRack* InVizRack)
{
	VizRack = InVizRack;
}

void UEquipRack::EquipItem(UItemMem* ItemToAdd)
{
	if (ItemToAdd->HasViz())
	{
		TArray<UViz*> Vizs = ItemToAdd->GetViz();
		
		for (UViz* Viz : Vizs)
		{
			Viz->SetSource(ItemToAdd);
			VizRack->AddViz(Viz);
		}
	}
}

void UViz::SetSource(UObject* Object)
{
	Source = Object;
}


void UEquipRack::RemoveItem(UItemMem* ItemToRemove)
{
	if (ItemToRemove->HasViz())
	{
		VizRack->RemoveVizBySource(ItemToRemove);
	}
}