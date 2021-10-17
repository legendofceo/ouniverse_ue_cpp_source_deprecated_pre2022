// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "InterfaceInput.generated.h"


class UCommand;
class UCommandAxis;
// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UInterfaceInput : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class ONE_API IInterfaceInput
{
	GENERATED_BODY()

public:


	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "InterfaceInput")
	void Command(UCommand* Command);
	virtual void Command_Implementation(UCommand* Command);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "InterfaceInput")
	void CommandAxis(UCommandAxis* Command);
	virtual void CommandAxis_Implementation(UCommandAxis* Command);

};