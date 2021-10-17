// Fill out your copyright notice in the Description page of Project Settings.


#include "State.h"


UState::UState()
{
	PrimaryComponentTick.bCanEverTick = false;
}


void UState::BeginPlay()
{
	Super::BeginPlay();
}