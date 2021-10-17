// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelZone.h"
#include "Log.h"

const FName ALevelZone::SYS = "LevelZone";

void ALevelZone::BeginPlay()
{
	Super::BeginPlay();
	LOG.S(SYS).W("BeginPlay()");
}