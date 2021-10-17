// Fill out your copyright notice in the Description page of Project Settings.


#include "Remote.h"


URemote::URemote()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void URemote::Init(AAppController* AP)
{
	AppPlayer = AP;
}

void URemote::BeginPlay()
{
	Super::BeginPlay();
}