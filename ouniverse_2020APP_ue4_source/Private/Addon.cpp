// Fill out your copyright notice in the Description page of Project Settings.


#include "Addon.h"


// Sets default values
AAddon::AAddon()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AAddon::Setup(AActra* InActra, UWearable* InWearable)
{
	Actra = InActra;
	Wearable = InWearable;
	DoAddonDisplay();
}