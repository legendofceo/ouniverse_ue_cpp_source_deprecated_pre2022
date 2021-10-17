// Fill out your copyright notice in the Description page of Project Settings.


#include "Mng/Mng.h"

AManagerActor::AManagerActor()
{
	bReplicates = true;
	bAlwaysRelevant = true;
	PrimaryActorTick.bCanEverTick = false;
}