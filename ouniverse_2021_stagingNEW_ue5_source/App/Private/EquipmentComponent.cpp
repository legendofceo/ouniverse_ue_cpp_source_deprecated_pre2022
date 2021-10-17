// Fill out your copyright notice in the Description page of Project Settings.


#include "EquipmentComponent.h"



UEquipmentComponent::UEquipmentComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UEquipmentComponent::Init(int Max)
{
	Slots.Init(FEquipSlot(), Max);
}