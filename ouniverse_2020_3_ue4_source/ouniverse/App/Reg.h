// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UObject/NoExportTypes.h"
#include "Ui/UiStyle.h"
#include "Reg.generated.h"

class AServer;
class UUi;

UCLASS(Abstract, Blueprintable)
class UReg : public UObject
{
	GENERATED_BODY()

public:

	static UReg* Create();
	static UReg* Get();
	
	UPROPERTY(EditAnywhere, meta = (Category = "App"))
	TSubclassOf<AServer>  ServerClass;

	UPROPERTY(EditAnywhere, meta = (Category = "Ui"))
	TSubclassOf<UUi>  UiClass;
	
	UPROPERTY(EditAnywhere, meta = (Category = "Ui"))
	FUiStyle LoadScreen;

	UPROPERTY(EditAnywhere, meta = (Category = "Ui"))
	FUiStyle SplashLegalUi;

};