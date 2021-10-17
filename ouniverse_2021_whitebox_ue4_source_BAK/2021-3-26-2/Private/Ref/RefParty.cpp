// Fill out your copyright notice in the Description page of Project Settings.


#include "Ref/RefParty.h"
#include "Pro/StoryPro.h"
#include "CompanionActor.h"

ARefParty::ARefParty()
{
	PrimaryActorTick.bCanEverTick = false;

}

void ARefParty::BeginPlay()
{
	Super::BeginPlay();
	
}

void ARefParty::GoHere()
{
	/**
	TArray<ACompanionActor*> PartyActors = UStoryPro::Get()->GetPartyActors();

	for (ACompanionActor* Actor : PartyActors)
	{
		Actor->SetActorLocation(GetActorLocation());
	}
	*/
}