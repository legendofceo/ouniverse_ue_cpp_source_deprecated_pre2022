// Fill out your copyright notice in the Description page of Project Settings.


#include "Status.h"


UStatus::UStatus()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UStatus::BeginPlay()
{
	Super::BeginPlay();
}