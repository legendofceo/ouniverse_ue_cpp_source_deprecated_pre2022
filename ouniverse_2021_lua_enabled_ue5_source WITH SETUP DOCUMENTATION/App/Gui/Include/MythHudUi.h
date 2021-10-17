// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MythHudUi.generated.h"

class UHudPartyUi;
class UHudCompassUi;

UCLASS(Abstract)
class APP_API UMythHudUi : public UUserWidget
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UHudPartyUi* HudPartyUi;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UHudCompassUi* HudCompassUi;


};
