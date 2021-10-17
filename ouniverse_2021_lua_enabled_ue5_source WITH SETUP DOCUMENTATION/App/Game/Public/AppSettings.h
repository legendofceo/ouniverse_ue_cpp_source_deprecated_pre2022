// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "InputDevices.h"
#include "AppSettings.generated.h"


UCLASS()
class APP_API UAppSettings : public UObject
{
	GENERATED_BODY()

	static const FName SYS;

public:

	UAppSettings();

	static UAppSettings* Get();

	UPROPERTY(VisibleAnywhere,BlueprintReadWrite)
	bool bStreamSafeMode = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool bInvertGamepadCamY = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool bInvertMouseCamY = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float MouseSensitivity = 1.0f;

	float InvertCamY(float Power, InputDevice Device);

};