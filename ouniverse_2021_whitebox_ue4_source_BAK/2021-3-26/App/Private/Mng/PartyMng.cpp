// Fill out your copyright notice in the Description page of Project Settings.


#include "Mng/PartyMng.h"
#include "Mng/CompanionMng.h"
#include "Playthrough.h"
#include "Story.h"
#include "Party.h"
#include "PartyMember.h"
#include "Companion.h"
#include "Task/Tasks.h"
#include "Task/CompanionLoadTask.h"

UPartyMng::UPartyMng()
{

	PrimaryComponentTick.bCanEverTick = false;

}

void UPartyMng::BeginPlay()
{
	Super::BeginPlay();
}


void UPartyMng::PlacePartyAtRef()
{

}

void UPartyMng::Init()
{

}

void UPartyMng::InitII(UPlaythrough* InPlaythrough, UCompanionMng* InCompanionMng)
{
	Playthrough = InPlaythrough;
	CompanionMng = InCompanionMng;
}

void UPartyMng::Load()
{
	LoadInProgress = true;
	Loaded = false;
	UParty* Party = Playthrough->ActiveStory->Party;

	//LoadCompanionsQue.Empty(5);

	PartyLoadTask = NewObject<UTasks>(this, UTasks::StaticClass());
	PartyLoadTask->OnComplete.AddDynamic(this, &UPartyMng::LoadComplete);

	for (UPartyMember* PartyMember : Party->PartyMembers)
	{
		if (PartyMember->Companion != NULL)
		{
			
			
			UCompanionLoadTask* CompanionLoadTask = NewObject<UCompanionLoadTask>(this, UCompanionLoadTask::StaticClass());
			CompanionLoadTask->Setup(PartyMember->Companion);
			PartyLoadTask->Add(CompanionLoadTask);
			//LoadCompanionsQue.Add(PartyMember->Companion);
			
			//CompanionLoaderQue.Add(CompanionLoaded);
			//CompanionLoaded->OnLoaded.AddDynamic(this,UPartyMng:LLoadCB);
			
			//LoadCompanion(Companion);
			
		}
	}

	PartyLoadTask->Go();
}

void UPartyMng::LoadComplete(UTask* Task)
{
	LoadInProgress = false;
	Loaded = true;

	PartyLoadTask->ConditionalBeginDestroy();
	PartyLoadTask = NULL;
	OnLoaded.Broadcast();
	//OnEmbodyPartyComplete.Broadcast();
}



void UPartyMng::Unload()
{

}
