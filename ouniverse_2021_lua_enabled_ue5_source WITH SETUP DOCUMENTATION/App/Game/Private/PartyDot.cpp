// Fill out your copyright notice in the Description page of Project Settings.


#include "PartyDot.h"


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
	/**
	AMythRemote* MythRemote = AMythRemote::Get();
	UPartyHandle* Handle = MythRemote->GetActivePartyHandle();


	for (UPartyMemberHandle* PM : Handle->PartyMemberHandles)
	{
		if (PM->HasActra())
		{
			PM->Actra3d->SetActorLocation(GetActorLocation());

		}
	}
	*/

	/**
	TArray<ACompanionActor*> PartyActors = UStoryPro::Get()->GetPartyActors();

	for (ACompanionActor* Actor : PartyActors)
	{
		Actor->SetActorLocation(GetActorLocation());
	}
	*/
}