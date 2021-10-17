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

void UCompanionMng::InitII(UPlaythrough* InPlaythrough)
{
	Playthrough = InPlaythrough;
}