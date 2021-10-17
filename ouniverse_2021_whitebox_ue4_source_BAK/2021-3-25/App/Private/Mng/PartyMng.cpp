// Fill out your copyright notice in the Description page of Project Settings.


#include "Mng/PartyMng.h"



UPartyMng::UPartyMng()
{

	PrimaryComponentTick.bCanEverTick = false;

}



void UPartyMng::BeginPlay()
{
	Super::BeginPlay();
}



void UPartyMng::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

