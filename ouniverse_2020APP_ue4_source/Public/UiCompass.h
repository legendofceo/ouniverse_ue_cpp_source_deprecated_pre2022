// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UiCompass.generated.h"

/**
 * 
 */

class APC;
class UCanvasPanel;
class UCanvasPanelSlot;
class UImage;

UCLASS()
class ETREIAAPP_API UUiCompass : public UUserWidget
{
	GENERATED_BODY()


public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	APC* PC;

	UFUNCTION(BlueprintImplementableEvent)
	void SetDirection();

	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
};
