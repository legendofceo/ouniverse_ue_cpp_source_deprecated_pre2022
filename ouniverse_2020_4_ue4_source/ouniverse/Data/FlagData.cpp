// Fill out your copyright notice in the Description page of Project Settings.


#include "FlagData.h"


UFlags* UFlags::Create()
{
	UFlags* Neu = NewObject<UFlags>();
	return Neu;
}

UFlags::UFlags()
{

}

void UFlags::Load(FFlagsMD InMD)
{

}

void UFlags::LoadQSB()
{

};

void UFlags::LoadQSC()
{

};

FFlagsMD UFlags::QuickData()
{
	return FFlagsMD();
};

FString UFlags::JsonData()
{
	return "";
};

