// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameViewportClient.h"
#include "AppViewport.generated.h"

/**
 * 
 */

UENUM(Blueprintable)
enum class EGameInputMethod : uint8
{
	GameInput_Default,
	GameInput_Player1OnlyKeyboardAndMouse,
};

UCLASS(Blueprintable)
class APP_API UAppViewport : public UGameViewportClient
{
	GENERATED_BODY()

public:

	//void AddCursorWidget(EMouseCursor::Type Cursor, UUserWidget* CursorWidget) override {};


	/**
	 
	// Input Method for the viewport
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Input")
		EGameInputMethod GameInputMethod;


	virtual bool InputKey(FViewport* tViewport, int32 ControllerId, FKey Key, EInputEvent EventType, float AmountDepressed = 1.f, bool bGamepad = false) override
	{
		if (GameInputMethod == EGameInputMethod::GameInput_Default)
			return Super::InputKey(tViewport, ControllerId, Key, EventType, AmountDepressed, bGamepad);

		if (GameInputMethod == EGameInputMethod::GameInput_Player1OnlyKeyboardAndMouse && bGamepad)
		{
			// shift gamepad input to controllers with +1 index
			++ControllerId;
			return Super::InputKey(tViewport, ControllerId, Key, EventType, AmountDepressed, bGamepad);
		}
		else
		{
			return Super::InputKey(tViewport, ControllerId, Key, EventType, AmountDepressed, bGamepad);
		}
	}

	virtual bool InputAxis(FViewport* tViewport, int32 ControllerId, FKey Key, float Delta, float DeltaTime, int32 NumSamples = 1, bool bGamepad = false) override
	{
		if (GameInputMethod == EGameInputMethod::GameInput_Default)
			return Super::InputAxis(tViewport, ControllerId, Key, Delta, DeltaTime, NumSamples, bGamepad);

		if (GameInputMethod == EGameInputMethod::GameInput_Player1OnlyKeyboardAndMouse && bGamepad)
		{
			// shift gamepad input to controllers with +1 index
			++ControllerId;
			return Super::InputAxis(tViewport, ControllerId, Key, Delta, DeltaTime, NumSamples, bGamepad);
		}
		else
		{
			return Super::InputAxis(tViewport, ControllerId, Key, Delta, DeltaTime, NumSamples, bGamepad);
		}
	}

	*/
};