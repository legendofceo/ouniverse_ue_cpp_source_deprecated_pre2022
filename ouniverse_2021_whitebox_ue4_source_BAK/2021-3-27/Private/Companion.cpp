// Fill out your copyright notice in the Description page of Project Settings.


#include "Companion.h"

ACompanion::ACompanion()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ACompanion::BeginPlay()
{
	Super::BeginPlay();
	
	DoMarshalBP();
}