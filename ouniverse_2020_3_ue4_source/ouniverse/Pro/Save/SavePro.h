// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Pro/Pro.h"
#include "SavePro.generated.h"

class AControl;
class USaveMenuUi;

UCLASS()
class OUNIVERSE_API USavePro : public UPro
{
	GENERATED_BODY()


public:

	static USavePro* Create();

private:

	USaveMenuUi* Menu_;


};