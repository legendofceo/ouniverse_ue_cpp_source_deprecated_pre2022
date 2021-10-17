// Fill out your copyright notice in the Description page of Project Settings.


#pragma once

#include "base.h"
#include "party.generated.h"



UCLASS()
class AParty : public ABase
{

	GENERATED_BODY()

public:

	static AParty* Create(AActor* WorldActor);
	static AParty* Get();

};