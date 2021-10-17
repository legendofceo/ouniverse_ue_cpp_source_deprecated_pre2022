 // Fill out your copyright notice in the Description page of Project Settings.


#include "AGS.h"
#include "Reg.h"

namespace Global
{
	AGS* GameState;
}

AGS::AGS()
{
	Global::GameState = this;
}

AGS* AGS::GetGS()
{
	return Global::GameState;
}

// Called when the game starts or when spawned
void AGS::BeginPlay()
{
	Super::BeginPlay();
	Reg = NewObject<UReg>(this, RegClass.Get(),"Reg");
	Reg->RegisterComponent();

}