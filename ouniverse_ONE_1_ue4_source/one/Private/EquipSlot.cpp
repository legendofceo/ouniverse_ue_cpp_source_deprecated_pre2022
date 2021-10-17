// Fill out your copyright notice in the Description page of Project Settings.


#include "EquipSlot.h"




void UEquipSlot::Setup(UBody* InBody, TEnumAsByte<EEquipSlots> InSlot)
{
	Body = InBody;
	Actra = InBody->Actra;
	Slot = InSlot;
}


void UEquipSlot::Equip(UEquipable* Equipable)
{
	
	Equipped = Equipable;
	Equipped->Setup(Actra);
}