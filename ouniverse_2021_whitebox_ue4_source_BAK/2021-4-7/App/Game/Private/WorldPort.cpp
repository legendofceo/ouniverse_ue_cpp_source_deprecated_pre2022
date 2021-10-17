// Fill out your copyright notice in the Description page of Project Settings.


#include "WorldPort.h"


UWorldPort::UWorldPort()
{

	PrimaryComponentTick.bCanEverTick = true;

}


void UWorldPort::BeginPlay()
{
	Super::BeginPlay();
}