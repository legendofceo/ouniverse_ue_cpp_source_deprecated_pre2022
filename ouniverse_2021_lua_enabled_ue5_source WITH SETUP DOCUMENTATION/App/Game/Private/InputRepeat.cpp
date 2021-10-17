// Fill out your copyright notice in the Description page of Project Settings.


#include "InputRepeater.h"
#include "Log.h"
#include "AppController.h"
#include "InputRaw.h"

const FName UInputRepeaterStatics::SYS = "InputRepeaterStatics";

void FInputRepeater::Reset()
{
	bFirstPassed = false;
	LastGateTriggeredDelta = 0.0f;
}

bool FInputRepeater::Update(UBT* BT)
{
	PassState = InputRepeaterPassState::Block;
	float Held = BT->GetTimeHeld();

	if (BT->IsClick())
	{
		Reset();
		
		if (bNoPassOnClick)
		{
			return false;
		}
		else
		{
			PassState = InputRepeaterPassState::Click;
			return true;
		}
	}

	if (!BT->IsSender())
	{
		Reset();
		return false;
	}

	if (BT->IsSender())
	{
		if (!bFirstPassed)
		{
			if (Held - LastGateTriggeredDelta > FirstGate)
			{
				LastGateTriggeredDelta = Held;
				bFirstPassed = true;
				PassState = InputRepeaterPassState::First;
				return true;
			}
		}
		else
		{
			if (Held - LastGateTriggeredDelta > RepeatGate)
			{
				LastGateTriggeredDelta = Held;
				PassState = InputRepeaterPassState::Repeat;
				return true;
			}
		}
	}
	return false;
}

void UInputRepeaterStatics::Update(FInputRepeater& RepeatGate, UBT* BT, EPassBlock& Execs, InputRepeaterPassState& PassState)
{
	Execs = EPassBlock::Block;

	if (!IsValid(BT))
	{
		LOG.S(SYS).T(TCRIT).W("BT is NULL").DebugM();
		return;
	}


	bool bPass = RepeatGate.Update(BT);

	if (bPass)
	{
		Execs = EPassBlock::Pass;
	}

	PassState = RepeatGate.PassState;
}