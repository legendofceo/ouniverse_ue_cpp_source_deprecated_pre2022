// Fill out your copyright notice in the Description page of Project Settings.


#include "PartyState.h"


namespace State
{
	UPartyState* Party = NULL;
}


UPartyState::UPartyState() : UState()
{
	State::Party = this;
}

UPartyState* UPartyState::Get()
{
	return State::Party;
}


void UPartyState::BeginPlay()
{
	Super::BeginPlay();
}

void UPartyState::NewActiveParty(UPartyHandle* PartyHandle)
{

}