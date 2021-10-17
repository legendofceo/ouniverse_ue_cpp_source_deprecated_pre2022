// Fill out your copyright notice in the Description page of Project Settings.


#include "Mng/MemMng.h"
#include "Mem.h"

UMemMng::UMemMng()
{

	PrimaryComponentTick.bCanEverTick = false;

}

void UMemMng::BeginPlay()
{
	Super::BeginPlay();
}

void UMemMng::Init(AMem* InMem)
{
	Mem = InMem;
}