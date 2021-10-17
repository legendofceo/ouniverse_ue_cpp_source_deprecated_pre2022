// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Pro/Pro.h"
#include "Maestro.generated.h"


class UUi;
class AControl;
class USplashPro;
class UWorldPro;

UCLASS()
class OUNIVERSE_API UMaestro : public UPro
{
	GENERATED_BODY()

public:

	static UMaestro* Create(AControl* InControl, UUi* InUi);
	void Init(AControl* InControl, UUi* InUi);

	void Start();

private:

	ProDockS Dock_;

	UPROPERTY()
	USplashPro* Splash_;

	UPROPERTY()
	UWorldPro* Universe_;

};
