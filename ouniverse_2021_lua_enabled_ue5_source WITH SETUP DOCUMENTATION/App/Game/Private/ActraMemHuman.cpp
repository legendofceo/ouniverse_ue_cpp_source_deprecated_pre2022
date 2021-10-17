// Fill out your copyright notice in the Description page of Project Settings.


#include "ActraMemHuman.h"
#include "Log.h"
#include "BodyMemHuman.h"
#include "Head.h"
#include "Hair.h"
#include "Viz.h"
#include "EquipRackHuman.h"

const FName UActraMemHuman::SYS = "ActraHuman";

void UActraMemHuman::BeginInit()
{

	BodyMemHuman = NewObject<UBodyMemHuman>(this, BodyHumanClass.Get());

	VizRack = NewObject<UVizRack>(this, UVizRack::StaticClass());
	EquipRackHuman = NewObject<UEquipRackHuman>(this, UEquipRackHuman::StaticClass());
	EquipRackHuman->Init(VizRack);

	HeadHuman = NewObject<UHeadHuman>(this, HeadHumanClass.Get());
	HeadHuman->Init(VizRack);


	//HairHuman = NewObject<UHairHuman>(this, HairHumanClass.Get());
	//HairHuman->Init(VizRack);


	BodyMemHuman = NewObject<UBodyMemHuman>(this, BodyHumanClass.Get());
	BodyMemHuman->Init(VizRack);


	BeginInitBP();
}

bool UActraMemHuman::Validate()
{
	if (!UActraMem::Validate()) {return false;}
	
	if (!BodyHumanClass)
	{
		LOG.S(SYS).T(TCRIT).W("Missing: BodyHumanClass").DebugM();
		return false;
	}

	if (!HeadHumanClass)
	{
		LOG.S(SYS).T(TCRIT).W("Missing: HeadHumanClass").DebugM();
		return false;
	}

	return true;
}
