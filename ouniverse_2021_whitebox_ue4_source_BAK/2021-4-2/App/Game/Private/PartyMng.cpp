// Fill out your copyright notice in the Description page of Project Settings.


#include "PartyMng.h"
#include "PartyHandle.h"

namespace Manager
{
	APartyMng* Party = NULL;
}

APartyMng::APartyMng()
{
	bReplicates = true;
	bAlwaysRelevant = true;
	PrimaryActorTick.bCanEverTick = false;
}

APartyMng* APartyMng::Get()
{
	return Manager::Party;
}

void APartyMng::GetPartyMngBP(APartyMng*& StoryMng)
{
	StoryMng = Manager::Party;
}

void APartyMng::BeginPlay()
{
	Manager::Party = this;

	Log.Write(AAUTH, LNORM, VNONE, 1, 0, "Init()");
	bInit = true;
	OnInitComplete.Broadcast(this);
}

void APartyMng::LoadParty(FParty* InActiveParty)
{
	Log.Write(AAUTH, LNORM, VNONE, 1, 0, "Loading Party.");
	ActiveParty = InActiveParty;

	ActivePartyHandle = NewObject<UPartyHandle>(this, UPartyHandle::StaticClass());
	ActivePartyHandle->OnLoadComplete.AddDynamic(this, &APartyMng::LoadPartyComplete);
	ActivePartyHandle->Init(ActiveParty);
	ActivePartyHandle->BufferActra();
	
}

void APartyMng::LoadPartyComplete()
{
	Log.Write(AAUTH, LNORM, VNONE, 1, 0, "Load Party Complete.");
	OnLoadComplete.Broadcast();
}

void APartyMng::EngagePartyBP()
{

}