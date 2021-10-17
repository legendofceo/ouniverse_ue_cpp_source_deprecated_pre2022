// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "InterfacePilot.generated.h"

class APC;
class UCameraComponent;

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UInterfacePilot : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class ONE_API IInterfacePilot
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	//UFUNCTION(BlueprintCallable, Category = "MyCategory")
	//virtual bool ReactToHighNoon();



	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "ControlInterface")
	APawn* GetPilotGoal();
	virtual APawn* GetPilotGoal_Implementation();


	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "ControlInterface")
	UCameraComponent* GetPilotCamera();
	virtual UCameraComponent* GetPilotCamera_Implementation();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "ControlInterface")
	void Engage(APC* PC);
	virtual void Engage_Implementation(APC* PC);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "ControlInterface")
	void Disengage();
	virtual void Disengage_Implementation();

};