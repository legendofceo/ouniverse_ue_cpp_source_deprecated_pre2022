// Fill out your copyright notice in the Description page of Project Settings.


#include "Pro.h"
#include "Components/SceneComponent.h"


UPro::UPro()
{
	PrimaryComponentTick.bCanEverTick = false;
}


// Called when the game starts
void UPro::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void UPro::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UPro::BT(UDataBT* Event)
{

}

void UPro::AX(UDataBT* Event)
{

}