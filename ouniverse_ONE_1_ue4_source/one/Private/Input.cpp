// Fill out your copyright notice in the Description page of Project Settings.


#include "Input.h"
#include "APC.h"
#include "Command.h"

void UBindSpecial::Setup(APC* InPC, TEnumAsByte<ECommandSpecialID> InID, FName InAction)
{
	PC = InPC;
	ID = InID;
	PC->InputComponent->BindAction(InAction, IE_Pressed, this, &UBindSpecial::Press);
	PC->InputComponent->BindAction(InAction, IE_Released, this, &UBindSpecial::Release);
}

void UBindSpecial::Press()
{
	PC->SendSpecial(ID, true);
}

void UBindSpecial::Release()
{
	PC->SendSpecial(ID, false);
}

void UBindMak::Setup(APC* InPC, FName InAction)
{
	PC = InPC;
	PC->InputComponent->BindAction(InAction, IE_Pressed, this, &UBindMak::Press);
	PC->InputComponent->BindAction(InAction, IE_Released, this, &UBindMak::Release);
}


void UBindMak::Press()
{
	PC->AllowInputFromControl(EControlType::ControlTypeMak);

	UCommand* Command = NewObject<UCommand>();
	Command->ID = Clean;
	Command->PureModifier = true;
	Command->Pressed = true;
	Command->Held = 0.0f;
	Command->ControlType = EControlType::ControlTypeMak;
	PC->SendCommand(Command);
	Command->ConditionalBeginDestroy();
}

void UBindMak::Release()
{
	UCommand* Command = NewObject<UCommand>();
	Command->ID = Clean;
	Command->PureModifier = true;
	Command->Pressed = false;
	Command->Held = 0.0f;
	Command->ControlType = EControlType::ControlTypeMak;
	PC->SendCommand(Command);
	Command->ConditionalBeginDestroy();
}


void UBindPad::Setup(APC* InPC, TEnumAsByte<EInputPad> InID, FName InKeyID)
{
	PC = InPC;
	ID = InID;
	PC->InputComponent->BindKey(FKey(InKeyID), IE_Pressed, this, &UBindPad::Press);
	PC->InputComponent->BindKey(FKey(InKeyID), IE_Released, this, &UBindPad::Release);
}


void UBindPad::Press_Implementation()
{
	PC->AllowInputFromControl(EControlType::ControlTypePad);

	UCommand* Command = NewObject<UCommand>();
	Command->ID = Output.Open;
	Command->PureModifier = true;
	Command->Pressed = true;
	Command->Held = 0.0f;
	Command->ControlType = EControlType::ControlTypePad;
	PC->SendCommand(Command);
	Command->ConditionalBeginDestroy();
}

void UBindPad::Release_Implementation()
{
	UCommand* Command = NewObject<UCommand>();
	Command->ID = Output.Open;
	Command->PureModifier = true;
	Command->Pressed = false;
	Command->Held = 0.0f;
	Command->ControlType = EControlType::ControlTypePad;
	PC->SendCommand(Command);
	Command->ConditionalBeginDestroy();
}


void UBindAxis::Setup(APC* InPC, TEnumAsByte<EInputAxis> InID, FName InKeyID, TEnumAsByte<EControlType> InControlType)
{
	PC = InPC;
	ID = InID;
	ControlType = InControlType;
	PC->InputComponent->BindAxisKey(FKey(InKeyID), this, &UBindAxis::Axis);
}

void UBindAxis::Enable(bool bOn)
{
	bEnabled = bOn;
}

void UBindAxis::Axis(float Power)
{
	if (bEnabled)
	{
		UCommandAxis* Command = NewObject<UCommandAxis>();
		Command->ID = Clean;
		Command->PureModifier = true;
		Command->Power = Power;
		Command->ControlType = EControlType::ControlTypePad;
		PC->SendCommandAxis(Command);
		Command->ConditionalBeginDestroy();
	}
}

void UBindAxisFaux::Setup(APC* InPC, TEnumAsByte<EInputAxis> InID, FName InKey1, FName InKey2)
{
	PC = InPC;
	ID = InID;
	KeyUp = FKey(InKey1);
	KeyDown = FKey(InKey2);
}

void UBindAxisFaux::Trigger()
{
	if (bEnabled)
	{
		bool bKeyUp = PC->IsInputKeyDown(KeyUp);
		bool bKeyDown = PC->IsInputKeyDown(KeyDown);
		float Power = 0.0f;

		if (bKeyUp && !bKeyDown)
		{
			Power = 1.0f;
		}
		else if (!bKeyUp && bKeyDown)
		{
			Power = -1.0f;
		}

		UCommandAxis* Command = NewObject<UCommandAxis>();
		Command->ID = Clean;
		Command->PureModifier = true;
		Command->Power = Power;
		Command->ControlType = EControlType::ControlTypeMak;
		PC->SendCommandAxis(Command);
		Command->ConditionalBeginDestroy();
	}
}

void UBindAxisFaux::Enable(bool bOn)
{
	bEnabled = bOn;
}