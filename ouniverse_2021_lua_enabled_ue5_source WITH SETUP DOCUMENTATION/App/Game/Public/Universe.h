// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ObjectPlus.h"
#include "Universe.generated.h"



struct FUniverseMem;

UCLASS(Abstract,BlueprintType,Blueprintable)
class APP_API UUniverse : public UObjectPlus
{
	GENERATED_BODY()

public:

	UUniverse() {};	

	FUniverseMem* Mem;

};