// Fill out your copyright notice in the Description page of Project Settings.


#include "Dot/PartyDot.h"
#include "PartyHandle.h"
#include "PartyMemberHandle.h"
#include "CompanionActor.h"
#include "WorldAnnex.h"
APartyDot::APartyDot()
{
	PrimaryActorTick.bCanEverTick = false;

}

void APartyDot::BeginPlay()
{
	Super::BeginPlay();
	
}

void APartyDot::GoHere()
{
	UWorldAnnex* WorldAnnex = UWorldAnnex::Get();
	UPartyHandle* Handle = WorldAnnex->GetActivePartyHandle();


	for (UPartyMemberHandle* PM : Handle->PartyMembers)
	{
		if (PM->HasCompanion())
		{
			PM->CompanionA->SetActorLocation(GetActorLocation());

		}
	}

	/**
	TArray<ACompanionActor*> PartyActors = UStoryPro::Get()->GetPartyActors();

	for (ACompanionActor* Actor : PartyActors)
	{
		Actor->SetActorLocation(GetActorLocation());
	}
	*/
}