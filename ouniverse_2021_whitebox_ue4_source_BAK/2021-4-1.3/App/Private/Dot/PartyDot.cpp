// Fill out your copyright notice in the Description page of Project Settings.


#include "Dot/PartyDot.h"
#include "Mng/PartyMng.h"
#include "Handle/PartyHandle.h"

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
	APartyMng* PartyMng = APartyMng::Get();
	UPartyHandle* Handle = PartyMng->ActivePartyHandle;



	/**
	TArray<ACompanionActor*> PartyActors = UStoryPro::Get()->GetPartyActors();

	for (ACompanionActor* Actor : PartyActors)
	{
		Actor->SetActorLocation(GetActorLocation());
	}
	*/
}