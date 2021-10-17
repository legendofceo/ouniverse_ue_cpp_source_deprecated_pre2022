// Fill out your copyright notice in the Description page of Project Settings.


#include "Input.h"
#include "AppController.h"

UInputButton* UInputButton::Create(AAppController* PC, const FKey* Key, TEnumAsByte<EInputBT> InputCode)
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








void UInputButtonEvent::Fill(UInputButton* InputButton)
{
	InputCode = InputButton->InputCode;
	bPressed = InputButton->bPressed;
}

uint8 UInputButtonEvent::GetInputCode()
{
	return InputCode;
}

bool UInputButtonEvent::IsPressed()
{
	return bPressed;
}

bool UInputButtonEvent::IsHandled()
{
	return bHandled;
}

void UInputButtonEvent::GetInputCodeBP(uint8& Code)
{
	Code = InputCode;
}

void UInputButtonEvent::IsPressedBP(EPressedExecs& Execs)
{
	Execs = EPressedExecs::Released;
	if (bPressed)
	{
		Execs = EPressedExecs::Pressed;
	}
}

void UInputButtonEvent::IsHandledBP(EHandledExecs& Execs)
{
	Execs = EHandledExecs::Unhandled;
	if (bHandled)
	{
		Execs = EHandledExecs::Handled;
	}
}