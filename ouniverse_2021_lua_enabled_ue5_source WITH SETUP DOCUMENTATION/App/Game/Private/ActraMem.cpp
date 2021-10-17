// Fill out your copyright notice in the Description page of Project Settings.


#include "ActraMem.h"
#include "Log.h"
#include "BodyMem.h"
#include "Inventory.h"

const FName UActraMem::SYS = "Actra";

void UActraMem::Init()
{
	Inventory = FInventory();
	BeginInit();
	
}

bool UActraMem::Validate()
{
	
	return true;
}