// Fill out your copyright notice in the Description page of Project Settings.

#include "calendar.h"



namespace Global
{
	ACalendar* Calendar;
}


ACalendar* ACalendar::Create(AActor* WorldActor)
{
	ACalendar* N = WorldActor->GetWorld()->SpawnActor<ACalendar>(FVector(0.0f, 0.0f, 0.0f), FRotator(0.0f, 0.0f, 0.0f));
	ACalendar* Calendar = N;
	return N;
}

ACalendar* ACalendar::Get()
{
	return Global::Calendar;
}
