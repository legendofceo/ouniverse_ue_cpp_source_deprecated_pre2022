// Fill out your copyright notice in the Description page of Project Settings.

#include "AGM.h"
#include "APC.h"
#include "AGS.h"
#include "Context.h"
#include "Actra.h"
#include "Memory.h"
#include "Party.h"

AGM::AGM()
{
	//PlayerControllerClass = 
	//HUDClass = AHudUE::StaticClass();
	//DefaultPawnClass = ADefaultPawnPlus::StaticClass();
	//PlayerControllerClass = AOneController::StaticClass();
	//GameStateClass = AGM::StaticClass();

	Memory = CreateDefaultSubobject<UMem>("Memory");
}

AGM* AGM::GetGM()
{
	return Cast<AGM>(UContext::Get()->GetWorld()->GetAuthGameMode());
}


void AGM::BeginPlay()
{
	FActorSpawnParameters SpawnInfo;
	SpawnInfo.bNoFail = true;
	SpawnInfo.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
	Party = GetWorld()->SpawnActor<AParty>(FVector(0.0f,0.0f,0.0f), FRotator(0.0f,0.0f,0.0f), SpawnInfo);
	AGS::GetGS()->Party = Party;
}

void AGM::NewGame()
{
	
}

void AGM::LoadGame()
{

}

void AGM::AddPlayer(APC* PlayerController)
{
	PlayerController->PlayerIndex = Players.Num();
	Players.Add(PlayerController);
}

void AGM::SpawnParty()
{
	/**
	Players[0]->Pilot(Party[0]);
	Players[0]->MatchCamera(Party[0]->FollowCamera);

	if (Players.Num() == 2)
	{
		Players[1]->Pilot(Party[1]);
		Players[1]->MatchCamera(Party[1]->FollowCamera);
	}
	*/
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("AGM Spawn Party"));

	FVector Location(0.0f, 0.0f, 0.0f);
	FRotator Rotation(0.0f, 0.0f, 0.0f);
	FActorSpawnParameters SpawnInfo;
	SpawnInfo.bNoFail = true;
	SpawnInfo.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
	AActra* PM1 = GetWorld()->SpawnActor<AActra>(Location, Rotation, SpawnInfo);
	AActra* PM2 = GetWorld()->SpawnActor<AActra>(Location, Rotation, SpawnInfo);
	AActra* PM3 = GetWorld()->SpawnActor<AActra>(Location, Rotation, SpawnInfo);

	PM1->CreateAsPartyMember("fione");
	PM2->CreateAsPartyMember("fione");
	PM3->CreateAsPartyMember("fione");

	Party->PartyMembers[0]->SetActra(PM1);
	Party->PartyMembers[1]->SetActra(PM2);
	Party->PartyMembers[2]->SetActra(PM3);

	Players[0]->ConnectToParty();
}