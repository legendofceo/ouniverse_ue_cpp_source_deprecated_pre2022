// Fill out your copyright notice in the Description page of Project Settings.


#include "Remote.h"


ARemote::ARemote()
{
	bReplicates = true;
	bAlwaysRelevant = true;
	PrimaryActorTick.bCanEverTick = false;
}


// Called when the game starts
void ARemote::BeginPlay()
{
	Super::BeginPlay();
}