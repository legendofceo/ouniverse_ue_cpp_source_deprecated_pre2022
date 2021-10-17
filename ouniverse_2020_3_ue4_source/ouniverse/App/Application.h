// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/GameInstance.h"
#include "Application.generated.h"


class UMajor;

UENUM(BlueprintType)
enum class EBootMethod : uint8
{
	Standard 	UMETA(DisplayName = "Standard"),
	Test 		UMETA(DisplayName = "Test"),
	UiIso		UMETA(DisplayName = "UiIso"),
	Scribe		UMETA(DisplayName = "Scribe")
};


UCLASS(Abstract)
class UApp : public UGameInstance
{
	GENERATED_BODY()

public:

	//Call this from any level blueprint to begin the OUniverse boot process. Must be called only once.
	UFUNCTION(BlueprintCallable, Category = "OUniverse", meta = (WorldContext = "WorldContextObject", ShowWorldContextPin))
	void BootOUniverse(EBootMethod BootMethod, UObject* WorldContextObject);

	static UApp* Get();

	EBootMethod BootMethod_;

	void Standard(UObject* WorldContextObject);

private:

	UMajor* Major_;
};