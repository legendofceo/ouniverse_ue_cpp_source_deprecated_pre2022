// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Delegate.h"
#include "ButtonUi.generated.h"


UENUM(BlueprintType)
enum class EButtonEvents : uint8
{
	Hover  UMETA(DisplayName = "Hover"),
	Unhover  UMETA(DisplayName = "Unhover"),
	LeftClick  UMETA(DisplayName = "LeftClick"),
	RightClick  UMETA(DisplayName = "RightClick"),
	LeftDown  UMETA(DisplayName = "LeftDown"),
	LeftUp  UMETA(DisplayName = "LeftUp"),
	RightDown  UMETA(DisplayName = "RightDown"),
	RightUp  UMETA(DisplayName = "RightUp"),
	MAX UMETA(DisplayName = "MAX"),
};

DECLARE_DYNAMIC_DELEGATE_OneParam(FDelDynamicButtonEvent, EButtonEvents, ButtonEvent);

UCLASS(BlueprintType,Blueprintable)
class APP_API UButtonUi : public UUserWidget
{
	GENERATED_BODY()

public:

	FReply NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InButtonEvent) override;
	FReply NativeOnMouseButtonUp(const FGeometry& InGeometry, const FPointerEvent& InButtonEvent) override;
	void NativeOnMouseEnter(const FGeometry& InGeometry, const FPointerEvent& InButtonEvent) override;
	void NativeOnMouseLeave(const FPointerEvent& InButtonEvent) override;

	UFUNCTION(BlueprintCallable,meta=(DisplayName="#Subscribe"))
	void Subscribe(const FDelDynamicButtonEvent& Event);

	FDelDynamicButtonEvent OnButtonEvent;

};