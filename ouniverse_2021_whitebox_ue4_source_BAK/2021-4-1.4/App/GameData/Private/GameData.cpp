// Fill out your copyright notice in the Description page of Project Settings.


#include "GameData.h"

UGameData::UGameData()
{

}

void UGameData::Init()
{

}

void UGameData::InitSS()
{
	OnInitComplete.Broadcast();
}