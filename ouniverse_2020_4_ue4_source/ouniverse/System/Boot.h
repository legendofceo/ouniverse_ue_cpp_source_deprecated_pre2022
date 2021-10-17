// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "Boot.generated.h"

UENUM(BlueprintType)
enum class EBootMethod : uint8
{
	Standard 	UMETA(DisplayName = "Standard"),
	Test 		UMETA(DisplayName = "Test"),
	UiIso		UMETA(DisplayName = "UiIso"),
	Scribe		UMETA(DisplayName = "Scribe")
};


UCLASS()
class UBoot : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	//Call this from any level blueprint to begin the OUniverse boot process. Must be called only once.
	UFUNCTION(BlueprintCallable, Category = "OUniverse", meta = (WorldContext = "WorldContextObject", ShowWorldContextPin))
		static void Boot(EBootMethod BootMethod, UObject* WorldContextObject);

};


class BootC
{

public:

	static BootC* Get();
	static BootC* Create(EBootMethod InBootMethod, UObject* WorldContextObject);

	BootC() {};

	EBootMethod BootMethod_;

	BootC(EBootMethod InBootMethod, UObject* WorldContextObject);

	void Standard(UObject* WorldContextObject);
};