// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Blueprint/UserWidget.h"
#include "UiBase.generated.h"


UENUM(BlueprintType)
enum class EUiEvent : uint8 {
	Focus UMETA(DisplayName = "Focus"),
	Unfocus UMETA(DisplayName = "Unfocus"),
};

UCLASS(Abstract, Blueprintable)
class OUNIVERSE_API UUiBase : public UUserWidget
{

	GENERATED_BODY()

public:


	int BaseID;

	//virtual void EventUi(int WidgetID, int InEventID, UUserWidget* InWidget) {};

	
	virtual void Event(EUiEvent EventID, int Aux) { EventBP(EventID, Aux); };

	UFUNCTION(BlueprintImplementableEvent)
	void EventBP(EUiEvent EventID, int Aux);

	UFUNCTION(BlueprintImplementableEvent)
	void CodeBP(int EventID, int Aux);

	void Hide();
	
	void Show();

};