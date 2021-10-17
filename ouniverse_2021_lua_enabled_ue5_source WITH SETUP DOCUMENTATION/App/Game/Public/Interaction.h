// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ObjectPlus.h"
#include "Interaction.generated.h"

class UUserWidgetUi;

UCLASS(Abstract,Blueprintable,BlueprintType)
class APP_API UInteraction : public UObjectPlus
{
	GENERATED_BODY()


public:

	UInteraction();

	UFUNCTION(BlueprintCallable,meta=(DisplayName="#Get InteractiveUi Element"))
	UUserWidget* GetInteractiveUiElement();
};