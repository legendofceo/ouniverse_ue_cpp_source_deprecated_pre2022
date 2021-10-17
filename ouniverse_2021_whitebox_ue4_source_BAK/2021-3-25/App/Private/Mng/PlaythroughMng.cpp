// Fill out your copyright notice in the Description page of Project Settings.


#include "Mng/PlaythroughMng.h"



UPlaythroughMng::UPlaythroughMng()
{

	PrimaryComponentTick.bCanEverTick = false;

}



void UPlaythroughMng::BeginPlay()
{
	Super::BeginPlay();

}

void UPlaythroughMng::Init(AAppMem* InAppMem)
{
	AppMem = InAppMem;
}

void UPlaythroughMng::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}


void UPlaythroughMng::NewGame()
{
	NewGameBP();
	//Crash here means mem was not created first.
	//UStory* StartStory = AppMem->GetStory(UStoryKeys::Primary);
	//StartStory->Obtain();
}