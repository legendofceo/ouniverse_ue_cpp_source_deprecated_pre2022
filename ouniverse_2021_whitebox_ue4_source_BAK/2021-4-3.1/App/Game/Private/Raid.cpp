// Fill out your copyright notice in the Description page of Project Settings.


#include "Raid.h"

const int FRaid::RaidMaxParties = 5;

FRaid::FRaid()
{

	for (int i = 0; i < FRaid::RaidMaxParties; i++)
	{
		Parties.Add(FParty());
	}
}
