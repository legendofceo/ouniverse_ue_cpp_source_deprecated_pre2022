// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "AnythingUiFetch.h"
#include "InteractiveMutual.generated.h"

class UAnythingUi;

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UInteractiveMutual : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class APP_API IInteractiveMutual
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "InteractiveMutual", meta = (DisplayName = "@GetInteractiveName"))
	FText GetInteractiveName();
	virtual FText GetInteractiveName_Implementation();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "InteractiveMutual", meta = (DisplayName = "@GetInteractiveUi"))
	void GetInteractiveUi(const FAnythingUiFetch& Fetch);
	virtual void GetInteractiveUi_Implementation(const FAnythingUiFetch& Fetch);

};