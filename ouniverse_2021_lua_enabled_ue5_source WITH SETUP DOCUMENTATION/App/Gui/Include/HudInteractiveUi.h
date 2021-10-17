// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AnythingUi.h"
#include "HudInteractiveUi.generated.h"

class UInteractiveComponent;
class UNamedSlot;

class AActra3d;

UCLASS(Abstract)
class APP_API UHudInteractiveUi : public UAnythingUi
{
	GENERATED_BODY()

	static const FName SYS;

public:

	virtual void NativeOnInitialized() override;
	virtual void NativeConstruct() override;

};

UCLASS(Abstract)
class APP_API UHudInteractiveActraUi : public UHudInteractiveUi
{
	GENERATED_BODY()

		static const FName SYS;

public:

	//UPROPERTY(BlueprintReadWrite, Category = "Default", meta=(ExposeOnSpawn = true))
	//AActra3d* Actra3d;

};