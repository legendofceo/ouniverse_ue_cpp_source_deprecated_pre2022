// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Protocol.h"

#include "../Ui/UiBase.h"
#include "OmniPro.generated.h"




UCLASS(Abstract, Blueprintable)
class OUNIVERSE_API UOmniWin : public UUiBase
{

	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;

};

UCLASS()
class OUNIVERSE_API UOmniPro : public UProtocol
{
	GENERATED_BODY()

public:

	UOmniPro() {};

	static UOmniPro* Create();

	void Start();

	UOmniWin* Win_;
	
};