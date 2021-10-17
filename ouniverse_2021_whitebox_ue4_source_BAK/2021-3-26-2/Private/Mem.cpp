// Fill out your copyright notice in the Description page of Project Settings.


#include "Mem.h"
#include "Story.h"
#include "Companion.h"

AMem::AMem()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AMem::BeginPlay()
{
	Super::BeginPlay();
}

void AMem::AddStory(AStory* Story, FString Key, AStory*& Param)
{
	Stories.Add(Story);
	Param = Story;
	Marshal.RegObject(Key, &Param->Marshal);
	Story->AttachToActor(this,FAttachmentTransformRules::KeepRelativeTransform);
}

void AMem::AddCompanion(ACompanion* Companion, FString Key, ACompanion*& Param)
{
	Companions.Add(Companion);
	Param = Companion;
	Marshal.RegObject(Key, &Param->Marshal);
	Companion->AttachToActor(this,FAttachmentTransformRules::KeepRelativeTransform);
}