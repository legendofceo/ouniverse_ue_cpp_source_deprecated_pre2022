// Fill out your copyright notice in the Description page of Project Settings.


#pragma once

#include "base.h"
#include "music.generated.h"


UCLASS()
class AMusic : public ABase
{

	GENERATED_BODY()

public:

	static AMusic* Create(AActor* WorldActor);
	static AMusic* Get();

};