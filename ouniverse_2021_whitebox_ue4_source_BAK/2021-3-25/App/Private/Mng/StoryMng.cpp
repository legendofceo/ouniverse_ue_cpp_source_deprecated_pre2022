// Fill out your copyright notice in the Description page of Project Settings.


#include "Mng/StoryMng.h"
#include "Area.h"


UStoryMng::UStoryMng()
{
	PrimaryComponentTick.bCanEverTick = false;
}



void UStoryMng::BeginPlay()
{
	Super::BeginPlay();

}



void UStoryMng::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}