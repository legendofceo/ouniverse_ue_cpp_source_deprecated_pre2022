// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#pragma once

#include "UObject/Object.h"
#include "Interface/String.h"
#include "Save.generated.h"

class USave;
class USavePilot;

UCLASS()
class OUNIVERSE_API USaveLib : public UObject
{

	GENERATED_BODY()

public:

	USaveLib();

	TArray<USavePilot*> Pilots_;
};

UCLASS()
class OUNIVERSE_API USavePilot : public UObject
{

	GENERATED_BODY()

public:

	USavePilot();

};

UCLASS()
class OUNIVERSE_API USave : public UObject
{

	GENERATED_BODY()

public:

	USave();	

	TMap<int, int> Flags_;
};