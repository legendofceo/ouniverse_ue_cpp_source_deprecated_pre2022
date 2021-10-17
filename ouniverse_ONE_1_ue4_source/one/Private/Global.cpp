// Fill out your copyright notice in the Description page of Project Settings.


#include "AGI.h"


namespace Global
{
	UGI* Global;
}

UGI::UGI()
{
	Global::Global = this;
}

UGI* UGI::GetGlobal()
{
	return Global::Global;
}

UGI* UGI::Get()
{
	return Global::Global;
}


void UGI::Init()
{
	//Global = GetWorld()->SpawnActor<AGlobalActor>(AGlobalActor::StaticClass(), FVector(), FRotator());
	//Party = GetWorld()->SpawnActor<AParty>(AParty::StaticClass(), FVector(), FRotator());
}