// Fill out your copyright notice in the Description page of Project Settings.


#include "AppState.h"
#include "AppMode.h"
#include "MythState.h"
#include "PartyState.h"
#include "PartyMemberState.h"

namespace State
{
	AAppState* App;
}

AAppState::AAppState()
{
	MythState = CreateDefaultSubobject<UMythState>(TEXT("MythState"));
	PartyState = CreateDefaultSubobject<UPartyState>(TEXT("PartyState"));

	PartyMemberState1 = CreateDefaultSubobject<UPartyMemberState>(TEXT("PartyState1"));
	PartyMemberState2 = CreateDefaultSubobject<UPartyMemberState>(TEXT("PartyState2"));
	PartyMemberState3 = CreateDefaultSubobject<UPartyMemberState>(TEXT("PartyState3"));
	PartyMemberState4 = CreateDefaultSubobject<UPartyMemberState>(TEXT("PartyState4"));

	PartyState->PartyMemberStates.Add(PartyMemberState1);
	PartyState->PartyMemberStates.Add(PartyMemberState2);
	PartyState->PartyMemberStates.Add(PartyMemberState3);
	PartyState->PartyMemberStates.Add(PartyMemberState4);
}


AAppState* AAppState::GetAppState()
{
	return State::App;
}

void AAppState::BeginPlay()
{
	Super::BeginPlay();
	State::App = this;
	

#if (!UE_BUILD_SHIPPING)
	/**
	FBlueEnsureImplementation BEF = FBlueEnsureImplementation();
	BEF.Add("InitBP");
	BEF.Add("PreStartBP");
	BEF.Add("PostStartBP");
	BEF.Go(this, ID.ToString());
	*/
#endif

}