// Fill out your copyright notice in the Description page of Project Settings.


#include "PartyRemote.h"

UPartyRemote::UPartyRemote() : URemote(){}

void UPartyRemote::Init(AAppController* AP, UPartyPro* InPartyPro)
{
	URemote::Init(AP);
	PartyPro = InPartyPro;
}

void UPartyRemote::BeginPlay()
{
	Super::BeginPlay();
}

void UPartyRemote::Engage()
{

}