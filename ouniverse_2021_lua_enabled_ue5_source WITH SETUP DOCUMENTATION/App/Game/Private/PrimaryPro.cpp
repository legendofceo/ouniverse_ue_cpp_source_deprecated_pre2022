// Fill out your copyright notice in the Description page of Project Settings.


#include "PrimaryPro.h"
#include "Log.h"
#include "AppStream.h"
#include "AppWorld.h"
#include "TroopRemote.h"

const FName UPrimaryPro::SYS = "PrimaryPro";

namespace Paradigm
{
	UPrimaryPro* Primary = nullptr;
}

UPrimaryPro* UPrimaryPro::Get()
{
	return Paradigm::Primary;
}

void UPrimaryPro::GetBP(UPrimaryPro*& Primary)
{
	Primary = Paradigm::Primary;
}

void UPrimaryPro::Engage()
{

	//EngageBP();
}


void UPrimaryPro::ContinueJourney(FPact* Pact)
{
	FDelBasic Callback;
	Callback.BindUObject(this, &UPrimaryPro::TroopReady);
	TroopRemote->ChangePact(Pact,Callback);
}

void UPrimaryPro::TroopReady()
{
	//UArea* Area = Areas.FindRef("start_level");
	//Area->LoadBP();
}


void UPrimaryPro::EnterTroopMode()
{
	TroopRemote->Engage();
}