// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Blueprint/UserWidget.h"
#include "ico.generated.h"



UCLASS(Abstract, Blueprintable)
class UIco_U : public UUserWidget
{

	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;

};

UCLASS(Abstract, Blueprintable)
class UIcoSlot_U : public UUserWidget
{

	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;

	UFUNCTION(BlueprintCallable)
	void SetIcoByID(int32 IconID);

	UFUNCTION(BlueprintImplementableEvent)
	void SetIco(UIco_U* InIco);

};