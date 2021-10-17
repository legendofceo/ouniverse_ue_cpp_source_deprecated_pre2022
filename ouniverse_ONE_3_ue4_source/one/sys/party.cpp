// Fill out your copyright notice in the Description page of Project Settings.

#include "party.h"


namespace Global
{
	AParty* Party;
}


AParty* AParty::Create(AActor* WorldActor)
{
	AParty* N = WorldActor->GetWorld()->SpawnActor<AParty>(FVector(0.0f, 0.0f, 0.0f), FRotator(0.0f, 0.0f, 0.0f));
	Global::Party = N;
	return N;
}

AParty* AParty::Get()
{
	return Global::Party;
}
