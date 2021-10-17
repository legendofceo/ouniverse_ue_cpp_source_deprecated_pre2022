// Fill out your copyright notice in the Description page of Project Settings.


#include "RemoteActraHuman.h"
#include "AppSettings.h"
#include "InputRaw.h"
#include "InputDevices.h"

void URemoteActraHuman::Init()
{
	/**
	Actra3d = InActra3d;
	bInit = true;
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;
	*/
}

void URemoteActraHuman::TurnAtRate(float Rate)
{
	/**
	// calculate delta for this frame from the rate information
	Actra3d->AddControllerYawInput(Rate * BaseTurnRate * Actra3d->GetWorld()->GetDeltaSeconds());
	*/
}

void URemoteActraHuman::TurnAtRateAX(UAX* AX)
{	
	TurnAtRate(AX->GetPower());
}


void URemoteActraHuman::LookUpAtRate(float Rate)
{
	/**
	// calculate delta for this frame from the rate information
	Actra3d->AddControllerPitchInput(Rate * BaseLookUpRate * Actra3d->GetWorld()->GetDeltaSeconds());
	*/
}

void URemoteActraHuman::LookUpAtRateAX(UAX* AX)
{
	LookUpAtRate(UAppSettings::Get()->InvertCamY(AX->GetPower(),AX->GetDevice()));
}

void URemoteActraHuman::MoveForward(float Value)
{
	/**
	if ((Actra3d->Controller != nullptr) && (Value != 0.0f))
	{
		// find out which way is forward
		const FRotator Rotation = Actra3d->Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		Actra3d->AddMovementInput(Direction, Value);
	}
	*/
}

void URemoteActraHuman::MoveForwardAX(UAX* AX)
{
	MoveForward(AX->GetPower());
}

void URemoteActraHuman::MoveRight(float Value)
{
	/**
	if ((Actra3d->Controller != nullptr) && (Value != 0.0f))
	{
		// find out which way is right
		const FRotator Rotation = Actra3d->Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		Actra3d->AddMovementInput(Direction, Value);
	}
	*/
}

void URemoteActraHuman::MoveRightAX(UAX* AX)
{
	/**
	MoveRight(AX->GetPower());
	*/
}