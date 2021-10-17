// Fill out your copyright notice in the Description page of Project Settings.


#include "HeroData.h"


UHeroPD::UHeroPD()
{

}

UHeroPD* UHeroPD::Create()
{
	UHeroPD* Neu = NewObject<UHeroPD>();
	return Neu;
}

UTroupe* UTroupe::Create()
{
	UTroupe* Neu = NewObject<UTroupe>();
	return Neu;
}

UTroupe::UTroupe()
{

}

void UTroupe::Load(FTroupeMD InMD)
{

}

void UTroupe::LoadQSB() 
{

};

void UTroupe::LoadQSC() 
{

};

FTroupeMD UTroupe::QuickData() 
{
	return FTroupeMD();
};

FString UTroupe::JsonData() 
{ 
	return ""; 
};