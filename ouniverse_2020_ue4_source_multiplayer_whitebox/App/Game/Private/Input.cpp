// Fill out your copyright notice in the Description page of Project Settings.


#include "Input.h"
#include "AppController.h"

UInputButton* UInputButton::Create(AAppController* PC, const FKey* Key, TEnumAsByte<InputEnumBT> InputCode)
{
	UInputButton* NewBT = NewObject<UInputButton>();
	NewBT->InputCode = InputCode;
	NewBT->PC = PC;
	PC->InputComponent->BindKey(*Key, EInputEvent::IE_Pressed, NewBT, &UInputButton::Pressed);
	PC->InputComponent->BindKey(*Key, EInputEvent::IE_Released, NewBT, &UInputButton::Released);
	return NewBT;
}


void UInputButton::Pressed()
{
	bPressed = true;
	PC->SendInputButtonEvent(this);
}


void UInputButton::Released()
{
	bPressed = false;
	PC->SendInputButtonEvent(this);
}








void UDataBT::Fill(UInputButton* InputButton)
{
	InputCode = InputButton->InputCode;
	bPressed = InputButton->bPressed;
}

uint8 UDataBT::GetInputCode()
{
	return InputCode;
}

bool UDataBT::IsPressed()
{
	return bPressed;
}

bool UDataBT::IsHandled()
{
	return bHandled;
}

void UDataBT::GetInputCodeBP(uint8& Code)
{
	Code = InputCode;
}

void UDataBT::IsPressedBP(EPressedExecs& Execs)
{
	Execs = EPressedExecs::Released;
	if (bPressed)
	{
		Execs = EPressedExecs::Pressed;
	}
}

void UDataBT::IsHandledBP(EHandledExecs& Execs)
{
	Execs = EHandledExecs::Unhandled;
	if (bHandled)
	{
		Execs = EHandledExecs::Handled;
	}
}