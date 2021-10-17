// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "LevelAreaInterface.generated.h"

class UArea;

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class ULevelAreaInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class APP_API ILevelAreaInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, meta = (DisplayName = "#LevelAreaBeginStart"))
	void LevelAreaBeginStart(UArea* Area);
	virtual void LevelAreaBeginStart_Implementation(UArea* Area);


};