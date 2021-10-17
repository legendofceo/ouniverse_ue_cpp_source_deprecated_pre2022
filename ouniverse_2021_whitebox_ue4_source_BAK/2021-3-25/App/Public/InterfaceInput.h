// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "InterfaceInput.generated.h"


class UInputButton;


// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UInterfaceInput : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class APP_API IInterfaceInput
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "InterfaceInput")
	void OnInputButton(UInputButtonEvent* InputEvent);
	virtual void OnInputButton_Implementation(UInputButtonEvent* InputEvent);
};