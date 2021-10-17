// Fill out your copyright notice in the Description page of Project Settings.


#include "CompanionKeys.h"

const int UCompanionKeys::Fione = 1;
const int UCompanionKeys::Misha = 2;


void UCompanionKeys::FioneKey(int& Key)
{
	Key = UCompanionKeys::Fione;
}

void UCompanionKeys::MishaKey(int& Key)
{
	Key = UCompanionKeys::Misha;
}