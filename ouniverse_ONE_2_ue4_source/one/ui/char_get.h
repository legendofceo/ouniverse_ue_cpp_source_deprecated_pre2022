// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Blueprint/UserWidget.h"
#include "Delegates\IDelegateInstance.h"
#include "char_get.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCharGet, const FString&, Char, bool, bIsBackspace);

UCLASS(Abstract, Blueprintable)
class ONE_API UCharGet_U : public UUserWidget
{

	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;

	FReply NativeOnKeyChar(const FGeometry& MyGeometry, const FCharacterEvent& InCharEvent) override;

	UPROPERTY(BlueprintAssignable)
	FOnCharGet OnCharGet;
};