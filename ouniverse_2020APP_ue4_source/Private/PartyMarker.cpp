// Fill out your copyright notice in the Description page of Project Settings.


#include "PartyMarker.h"
#include "AGM.h"
// Sets default values
APartyMarker::APartyMarker()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

void APartyMarker::SpawnActiveParty()
{
	AGM::GetGM()->SpawnParty();


}