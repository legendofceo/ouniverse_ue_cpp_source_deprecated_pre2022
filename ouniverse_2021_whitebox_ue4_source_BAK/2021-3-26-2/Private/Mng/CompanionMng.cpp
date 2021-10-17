// Fill out your copyright notice in the Description page of Project Settings.


#include "Mng/CompanionMng.h"


UCompanionMng::UCompanionMng()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UCompanionMng::BeginPlay()
{
	Super::BeginPlay();
}

void UCompanionMng::Init()
{

}

void UCompanionMng::InitII(APlaythrough* InPlaythrough)
{
	Playthrough = InPlaythrough;
}