// Fill out your copyright notice in the Description page of Project Settings.


#include "Mng/PartyMng.h"


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
