// Fill out your copyright notice in the Description page of Project Settings.


#include "BeastData.h"


UBeastiary* UBeastiary::Create()
{
	UBeastiary* Neu = NewObject<UBeastiary>();
	return Neu;
}

UBeastiary::UBeastiary()
{

}

void UBeastiary::Load(FBeastiaryMD InMD)
{

}

void UBeastiary::LoadQSB()
{

};

void UBeastiary::LoadQSC()
{

};

FBeastiaryMD UBeastiary::QuickData()
{
	return FBeastiaryMD();
};

FString UBeastiary::JsonData()
{ 
	return ""; 
};