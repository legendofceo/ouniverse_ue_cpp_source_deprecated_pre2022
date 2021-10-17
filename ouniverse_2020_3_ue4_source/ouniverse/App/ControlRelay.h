// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "App/Controllable.h"
#include "App/ControlData.h"
#include "UObject/ScriptInterface.h"
#include "ControlRelay.generated.h"


UCLASS(Abstract)
class OUNIVERSE_API UControlRelay : public UObject
{
	GENERATED_BODY()

public:

	virtual bool OnStroke(const FFKey& InCommand) { return false; };
	virtual bool OnAxis(const FFAxis& InAxis) { return false; };

};

UCLASS()
class OUNIVERSE_API UControlRelayInterface : public UControlRelay
{
	GENERATED_BODY()

public:

	virtual bool OnStroke(const FFKey& InCommand) override;
	virtual bool OnAxis(const FFAxis& InAxis) override;

	void SetRelay(UObject* InRelay);

	UPROPERTY()
	TScriptInterface<IControllable> Controllable_;

};