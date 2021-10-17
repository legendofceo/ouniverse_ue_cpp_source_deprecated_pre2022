// Fill out your copyright notice in the Description page of Project Settings.


#include "control_ue.h"


namespace Global
{
	AControlUE* Control;
}

AControlUE* AControlUE::Initialize(AActor* WorldActor)
{
	AControlUE* N = Cast<AControlUE>(UGameplayStatics::GetPlayerController(WorldActor, 0));
	Global::Control = N;
	N->Constructor();
	return N;
}

AControlUE* AControlUE::Get()
{
	return Global::Control;
}

void AControlUE::Constructor()
{
	ControlIndex = GetInputIndex();
	//InputComponent->BindKey(FKey("Gamepad_Special_Right"), IE_Pressed, this, &AControlUE::PAD_Start_D);
//InputComponent->BindKey(FKey("Gamepad_Special_Right"), IE_Released, this, &AControlUE::PAD_Start_U);

//InputComponent->BindKey(FKey("Gamepad_Special_Left"), IE_Pressed, this, &AControlUE::PAD_Select_D);
//InputComponent->BindKey(FKey("Gamepad_Special_Left"), IE_Released, this, &AControlUE::PAD_Select_U);

//InputComponent->BindKey(FKey("AnyKey"), IE_Released, this, &AControlUE::PAD_Select_U);
	//InputComponent->BindKey(FKey("`"), IE_Pressed, AUi::Get()->Console, &AConsoleUi::Poke);

	Escape.Constructor(this,"Escape Up", UControlID::Escape);
	InputComponent->BindKey(FKey("A"), IE_Pressed, Escape.Down.Trigger, &UControlEventTrigger::Pressed);
	InputComponent->BindKey(FKey("A"), IE_Released, Escape.Up.Trigger, &UControlEventTrigger::Released);
}

void AControlUE::SetMouseMode(bool bOn)
{
	bMouseMode = bOn;

	if (bMouseMode)
	{
		bShowMouseCursor = true;
		bEnableClickEvents = true;
	}
	else
	{
		bShowMouseCursor = false;
		bEnableClickEvents = false;
	}
}

void AControlUE::BindKeyboard(UInputListener* Listener, EStrokeKB Stroke, bool bBindPressed)
{
	switch (Stroke) {
	case EStrokeKB::StrokeKB_Escape:
		Escape.AddListener(Listener, bBindPressed);
		break;   
	case EStrokeKB::StrokeKB_Accept:

		break;
	}
}