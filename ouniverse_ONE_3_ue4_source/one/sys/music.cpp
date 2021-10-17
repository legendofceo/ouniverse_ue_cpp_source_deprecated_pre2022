// Fill out your copyright notice in the Description page of Project Settings.

#include "music.h"



namespace Global
{
	AMusic* Music;
}


AMusic* AMusic::Create(AActor* WorldActor)
{
	AMusic* N = WorldActor->GetWorld()->SpawnActor<AMusic>(FVector(0.0f, 0.0f, 0.0f), FRotator(0.0f, 0.0f, 0.0f));
	Global::Music = N;
	return N;
}

AMusic* AMusic::Get()
{
	return Global::Music;
}
