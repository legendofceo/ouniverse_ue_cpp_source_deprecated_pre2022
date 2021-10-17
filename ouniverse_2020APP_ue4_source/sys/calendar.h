// Fill out your copyright notice in the Description page of Project Settings.


#pragma once

#include "base.h"
#include "calendar.generated.h"



UCLASS()
class ACalendar : public ABase
{

	GENERATED_BODY()

public:

	static ACalendar* Create(AActor* WorldActor);
	static ACalendar* Get();

};