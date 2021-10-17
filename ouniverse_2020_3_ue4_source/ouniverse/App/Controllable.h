// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "App/ControlData.h"
#include "Controllable.generated.h"


UINTERFACE(BlueprintType)
class OUNIVERSE_API UControllable : public UInterface
{
	GENERATED_BODY()
};

class OUNIVERSE_API IControllable
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "InterfaceControllable")
	bool OnCommand(const FFKey& InCmd);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "InterfaceControllable")
	bool OnAxis(const FFAxis& InAxis);

};
