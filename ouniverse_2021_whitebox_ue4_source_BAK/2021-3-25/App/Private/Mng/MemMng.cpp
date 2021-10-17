// Fill out your copyright notice in the Description page of Project Settings.


#include "Mng/MemMng.h"
#include "AppMem.h"
#include "AppMode.h"
#include "StoryKeys.h"
#include "Story.h"

UMemMng::UMemMng()
{

	PrimaryComponentTick.bCanEverTick = false;

}



void UMemMng::BeginPlay()
{
	Super::BeginPlay();
}

void UMemMng::Init(AAppMem* InAppMem)
{
	AppMem = InAppMem;
}

void UMemMng::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}