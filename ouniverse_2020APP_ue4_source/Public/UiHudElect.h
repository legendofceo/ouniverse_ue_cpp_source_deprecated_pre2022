// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UiHudElect.generated.h"

/**
 * 
 */

class UNamedSlot;
class UUiElect;
class UUiElect;

UENUM(BlueprintType)
enum EElectDefaultLayoutStyle
{
	ElectStyleDefault			UMETA(DisplayName = "Default"),
};

UCLASS()
class ETREIAAPP_API UUiHudElect : public UUserWidget
{
	GENERATED_BODY()
	
public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UUiElect* ElectWidget;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UNamedSlot* Pin;

	void OpenElectWidget(UUiElect* ElectWidget);

	void ClearElect();
};



UCLASS()
class ETREIAAPP_API UUiElect : public UUserWidget
{
	GENERATED_BODY()

public:


};

UCLASS()
class ETREIAAPP_API UUiElectDefault : public UUiElect
{
	GENERATED_BODY()

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (ExposeOnSpawn = "true"))
	FText Title;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (ExposeOnSpawn = "true"))
	FText Subtitle;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (ExposeOnSpawn = "true"))
	FText ButtonLabel;


};