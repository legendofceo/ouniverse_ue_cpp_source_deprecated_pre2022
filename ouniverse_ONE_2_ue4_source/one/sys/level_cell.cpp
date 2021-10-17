// Fill out your copyright notice in the Description page of Project Settings.


#include "level_cell.h"

void ALevelCell::Start(AArea* InCosm, FName SparkCode)
{
	Cosm = InCosm;
	OnStart(SparkCode);
}