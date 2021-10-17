// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UiHud.generated.h"

/**
 * 
 */

class APC;
class UUiHudParty;
class UUiHudElect;

UCLASS()
class ETREIAAPP_API UUiHud : public UUserWidget
{
	GENERATED_BODY()
	
public:

	virtual void NativeConstruct() override;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UUiHudParty* Party;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UUiHudElect* Elect;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	APC* PC;
};
