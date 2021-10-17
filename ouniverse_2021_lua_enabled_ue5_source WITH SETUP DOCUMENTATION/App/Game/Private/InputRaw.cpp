// Fill out your copyright notice in the Description page of Project Settings.


#include "InputRaw.h"
#include "AppController.h"
#include "AppWorld.h"

bool UVirtualInput::IsHandled()
{
	return bHandled;
}

bool UVirtualInput::IsGamepad()
{
	if (Device == InputDevice::Gamepad)
	{
		return true;
	}
	return false;
	
}


InputDevice UVirtualInput::GetDevice()
{
	return Device;
}

void UVirtualInput::IsHandledBP(EHandledExecs& Execs)
{
	Execs = EHandledExecs::Unhandled;
	if (bHandled)
	{
		Execs = EHandledExecs::Handled;
	}
}


UBT* UBT::Create(AAppController* PC, const FKey* Key, InputCodeBT InputCode, InputDevice InDevice)
{
	UBT* NewBT = NewObject<UBT>();
	NewBT->InputCode = InputCode;
	NewBT->Device = InDevice;

	NewBT->PC = PC;
	PC->BTs[uint8(InputCode)] = NewBT;
	PC->InputComponent->BindKey(*Key, EInputEvent::IE_Pressed, NewBT, &UBT::Pressed);
	PC->InputComponent->BindKey(*Key, EInputEvent::IE_Released, NewBT, &UBT::Released);
	return NewBT;
}

void UBT::Pressed()
{
	bPressed = true;
	bHeld = false;
	bHandled = false;
	TimeHeld = 0.0f;
	TickDelegate = FTickerDelegate::CreateUObject(this, &UBT::Held);
	TickDelegateHandle = FTicker::GetCoreTicker().AddTicker(TickDelegate);
	Send();
}

bool UBT::Held(float Delta)
{
	bHeld = true;
	TimeHeld += Delta;

	Send();
	return true;
}

void UBT::Released()
{
	bPressed = false;
	bHandled = false;
	bHeld = false;
	TimeHeld = 0.0f;
	FTicker::GetCoreTicker().RemoveTicker(TickDelegateHandle);
	Send();
}

void UBT::Send()
{
	PC->BT(this);
}
float UBT::GetDelta()
{
	return UAppWorld::GetAppWorld()->GetDeltaSeconds();
}

float UBT::GetTimeHeld()
{
	return TimeHeld;
}

InputCodeBT UBT::GetInputCode()
{
	return InputCode;
}

uint8 UBT::GetInputByte()
{
	return uint8(InputCode);
}

bool UBT::IsPressed()
{
	return bPressed;
}

bool UBT::IsHeld()
{
	return bHeld;
}

bool UBT::IsClick()
{
	if (IsSender() && !IsHeld())
	{
		return true;
	}

	return false;
}

bool UBT::IsSender()
{
	if (IsPressed())
	{
		return true;
	}

	return false;
}

void UBT::GetInputCodeBP(InputCodeBT& Code)
{
	Code = InputCode;
}

void UBT::GetInputByteBP(uint8& Byte)
{
	Byte = uint8(InputCode);
}

void UBT::GetTimeHeldBP(float& Time)
{
	Time = TimeHeld;
}

void UBT::IsPressedBP(EPressedExecs& Execs)
{
	Execs = EPressedExecs::Released;
	if (bPressed)
	{
		Execs = EPressedExecs::Pressed;
	}
}

void UBT::IsClickBP(EYesNo& Execs)
{
	Execs = EYesNo::No;
	if (IsClick())
	{
		Execs = EYesNo::Yes;
	}
}


void UBT::IsHeldBP(EYesNo& Execs)
{
	Execs = EYesNo::No;
	if (bHeld)
	{
		Execs = EYesNo::Yes;
	}
}




uint8 UAX::GetCode()
{
	return uint8(InputCode);
}

void UAX::Update(float InPower)
{
	bHandled = false;
	Power = InPower;
	Send();
}

float UAX::GetPower()
{
	return Power;
}

void UAX::GetPowerBP(float& Pow)
{
	Pow = Power;
}

UAX* UAX::Create(AAppController* PC, const FKey* Key, InputCodeAX InputCode, InputDevice InDevice)
{
	UAX* AX = NewObject<UAX>();
	AX->InputCode = InputCodeAX(InputCode);
	AX->Device = InDevice;
	AX->PC = PC;
	PC->AXs[uint8(InputCode)] = AX;

	PC->InputComponent->BindAxisKey(*Key, AX, &UAX::Update);
	return AX;
}

void UAX::Send()
{
	PC->AX(this);
}