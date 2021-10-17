// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../Protocol.h"
#include "../../System/Input.h"

#include "../../Ui/UiBase.h"
#include "TitleCreditsPro.generated.h"




UCLASS(Abstract, Blueprintable)
class OUNIVERSE_API UTitleCreditsWin : public UUiBase
{

	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;

};

UCLASS()
class OUNIVERSE_API UTitleCreditsPro : public UProtocol, public InputC
{
	GENERATED_BODY()

public:

	UTitleCreditsPro() {};

	static UTitleCreditsPro* Create();

	void Link();

	UTitleCreditsWin* Win_;
	
	void BTN(StrokeC* S) override;

};