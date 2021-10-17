// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "EngageInterface.generated.h"


// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UEngageInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 *
 */
class APP_API IEngageInterface
{
	GENERATED_BODY()

		// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "EngageInterface", meta = (DisplayName = "@Engage"))
	void Engage();
	virtual void Engage_Implementation();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "EngageInterface", meta = (DisplayName = "@Disengage"))
	void Disengage();
	virtual void Disengage_Implementation();

};