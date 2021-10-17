// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Pro/Pro.h"
#include "SplashPro.generated.h"

class USplashLegalUi;

UCLASS()
class OUNIVERSE_API USplashPro : public UPro
{
	GENERATED_BODY()


public:

	static USplashPro* Create();

private:

	USplashLegalUi* View_;

	void OpenPro(ProDockS* InDock) override;

};
