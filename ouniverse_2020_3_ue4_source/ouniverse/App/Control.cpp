// Fill out your copyright notice in the Description page of Project Settings.


#include "App/Control.h"
#include "App/ControlRelay.h"
#include "Pro/Maestro.h"

void AControl::Init(UMaestro* InMaestro)
{
	Maestro_ = InMaestro;
}

void AControl::SetupInputComponent()
{
	Super::SetupInputComponent();
	InputComponent->BindKey(FKey("W"), IE_Pressed, this, &AControl::Up_D);
	InputComponent->BindKey(FKey("W"), IE_Released, this, &AControl::Up_U);

	InputComponent->BindKey(FKey("S"), IE_Pressed, this, &AControl::Down_D);
	InputComponent->BindKey(FKey("S"), IE_Released, this, &AControl::Down_U);

	InputComponent->BindKey(FKey("A"), IE_Pressed, this, &AControl::Left_D);
	InputComponent->BindKey(FKey("A"), IE_Released, this, &AControl::Left_U);

	InputComponent->BindKey(FKey("D"), IE_Pressed, this, &AControl::Right_D);
	InputComponent->BindKey(FKey("D"), IE_Released, this, &AControl::Right_U);

}

void AControl::SetLastSource(EControlSource InSource)
{
	LastSource_ = InSource;
}


void AControl::SendCommand(const FFKey& InCommand)
{
	Maestro_->OnStroke(InCommand);
}

void AControl::SendAxis(const FFAxis& InAxis)
{

}

void AControl::Up_D()
{
	bUpPressedKeyboard = true;
	SetLastSource(EControlSource::Keyboard);
	SendCommand(FFKey(ECommand::Up, false, EControlSource::Keyboard));
}

void AControl::Up_U()
{
	bUpPressedKeyboard = true;
	SetLastSource(EControlSource::Keyboard);
}

void AControl::Down_D()
{
	bUpPressedKeyboard = true;
	SetLastSource(EControlSource::Keyboard);
	//InputCommand(KeyS(InputID::Up_D, InputSource::Keyboard));
}

void AControl::Down_U()
{
	bUpPressedKeyboard = true;
	SetLastSource(EControlSource::Keyboard);
}

void AControl::Left_D()
{
	bUpPressedKeyboard = true;
	SetLastSource(EControlSource::Keyboard);
	//InputCommand(KeyS(InputID::Up_D, InputSource::Keyboard));
}

void AControl::Left_U()
{
	bUpPressedKeyboard = true;
	SetLastSource(EControlSource::Keyboard);
}

void AControl::Right_D()
{
	bUpPressedKeyboard = true;
	SetLastSource(EControlSource::Keyboard);
	//InputCommand(KeyS(InputID::Up_D, InputSource::Keyboard));
}

void AControl::Right_U()
{
	bUpPressedKeyboard = true;
	SetLastSource(EControlSource::Keyboard);
}