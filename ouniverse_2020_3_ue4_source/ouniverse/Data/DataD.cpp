// Fill out your copyright notice in the Description page of Project Settings.


#include "Data/DataD.h"
#include "Interface/Json.h"


void DataD::Load(JsonS* J)
{
	I_ = J->String("i");
	U_ = J->Int("u");
}


int DataD::U()
{
	return U_;
}

StringC DataD::I()
{
	return I_;
}