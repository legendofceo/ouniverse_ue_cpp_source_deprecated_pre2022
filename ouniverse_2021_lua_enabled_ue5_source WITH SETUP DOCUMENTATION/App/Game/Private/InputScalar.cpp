// Fill out your copyright notice in the Description page of Project Settings.


#include "InputScalar.h"
#include "AppWorld.h"


void UInputScalar::TimerTick()
{
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("OK!"));
}


void UInputScalar::Connect()
{
	bConnected = true;
	UAppWorld::GetAppWorld()->GetTimerManager().SetTimer(TimerHandle, this, &UInputScalar::TimerTick, 5.0f, true, 0.0f);
}


void UInputScalar::ConnectBP()
{
	Connect();
}

void UInputScalar::Disconnect()
{
	bConnected = false;
	if (GetWorld())
	{
		UAppWorld::GetAppWorld()->GetTimerManager().ClearTimer(TimerHandle);
		TimerHandle.Invalidate();
	}
}

void UInputScalar::DisconnectBP()
{
	Disconnect();
}

void UInputScalar::PlusPress()
{
	bPositivePressed = true;
	ComputeRawPower();
}


void UInputScalar::PlusRelease()
{
	bPositivePressed = false;
	ComputeRawPower();
}

void UInputScalar::PlusBP(bool Press)
{
	if (Press)
	{
		PlusPress();
	}
	else
	{
		PlusRelease();
	}
}

void UInputScalar::MinusPress()
{
	bNegativePressed = true;
	ComputeRawPower();
}

void UInputScalar::MinusRelease()
{
	bNegativePressed = false;
	ComputeRawPower();
}

void UInputScalar::MinusBP(bool Press)
{
	if (Press)
	{
		MinusPress();
	}
	else
	{
		MinusRelease();
	}
}

void UInputScalar::ComputeRawPower()
{
	if (!bPositivePressed && !bNegativePressed)
	{
		RawPower = 0.0f;
	}
	else if (bPositivePressed && !bNegativePressed)
	{
		RawPower = 1.0f;
	}
	else if (!bPositivePressed && bNegativePressed)
	{
		RawPower = -1.0f;
	}
	else if (bPositivePressed && bNegativePressed)
	{
		RawPower = 0.0f;
	}
}


float UInputScalar::GetPower()
{
	return RawPower;
}