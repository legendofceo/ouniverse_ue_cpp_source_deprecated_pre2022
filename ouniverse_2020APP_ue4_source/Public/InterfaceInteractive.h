// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "InterfaceInteractive.generated.h"

class UUiInterest;

class UUiElect;

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UInterfaceInteractive : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class ETREIAAPP_API IInterfaceInteractive
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	//UFUNCTION(BlueprintCallable, Category = "MyCategory")
	//virtual bool ReactToHighNoon();

	/**
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "InterfaceInteractive")
	float MaxInteractiveDistance();
	virtual float MaxInteractiveDistance_Implementation();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "InterfaceInteractive")
	UInteractor* GetFocus();
	virtual UInteractor* GetFocus_Implementation();
	*/

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "InterfaceInteractive")
	void InteractiveSelect();
	virtual void InteractiveSelect_Implementation();


	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "InterfaceInteractive")
	void InteractiveUnselect();
	virtual void InteractiveUnselect_Implementation();


	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "InterfaceInteractive")
	UUiElect* GetElectWidget();
	virtual UUiElect* GetElectWidget_Implementation();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "InterfaceInteractive")
	void InteractiveAccept();
	virtual void InteractiveAccept_Implementation();

};