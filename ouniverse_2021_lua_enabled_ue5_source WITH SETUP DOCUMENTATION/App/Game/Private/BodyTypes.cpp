// Fill out your copyright notice in the Description page of Project Settings.


#include "BodyTypes.h"


const int FBodyType::SBody = 1;
const int FBodyType::SHead = 2;

const int FBodyType::CHead = 1;
const int FBodyType::CChest = 2;
const int FBodyType::CLegs = 3;
const int FBodyType::CHands = 4;
const int FBodyType::CFeet = 5;

int FBodyType::Get()
{
    switch (Type) {
    case BodyTypes::Human:
        return GetHuman();
    case BodyTypes::Creature:
        return GetCreature();
        break;
    }

    return -1;
}

int FBodyType::GetHuman()
{
    return -1;
}

int FBodyType::GetCreature()
{
    return -1;
}