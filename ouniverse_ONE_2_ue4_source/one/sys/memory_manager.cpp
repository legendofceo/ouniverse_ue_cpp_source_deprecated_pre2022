// Fill out your copyright notice in the Description page of Project Settings.

#include "memory_manager.h"


namespace Global
{
	AMemoryManager* Memory;
}

AMemoryManager::AMemoryManager()
{

}

AMemoryManager* AMemoryManager::Create(AActor* WorldActor)
{
	Global::Memory = WorldActor->GetWorld()->SpawnActor<AMemoryManager>(FVector(0.0f, 0.0f, 0.0f), FRotator(0.0f, 0.0f, 0.0f));
	Global::Memory->Constructor();
	return Global::Memory;
}

AMemoryManager* AMemoryManager::Get()
{
	return Global::Memory;
}

void AMemoryManager::Constructor()
{

}