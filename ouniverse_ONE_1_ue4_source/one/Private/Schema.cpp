// Fill out your copyright notice in the Description page of Project Settings.


#include "Schema.h"


void USchema::BeginPlay()
{
	Actra = Cast<AActra>(GetOwner());
	Super::BeginPlay();	
}



/**
void UInputBeacon::Setup(UInputComponent* IC)
{
	UKeyBinds* KB = APC::GetPC()->KeyBinds;
	BuildKey(IC, KB->KeyUpBind, EInputKey::KeyUp);
	BuildKey(IC, KB->KeyDownBind, EInputKey::KeyDown);
	BuildKey(IC, KB->KeyLeftBind, EInputKey::KeyLeft);
	BuildKey(IC, KB->KeyRightBind, EInputKey::KeyRight);
	BuildKey(IC, KB->KeyInteractBind, EInputKey::KeyInteract);
	BuildKey(IC, KB->KeyTabBind, EInputKey::KeyTab);
	BuildKey(IC, "LeftMouseButton", EInputKey::KeyMouseLeft);
	BuildKey(IC, "RightMouseButton", EInputKey::KeyMouseRight);


	BuildAxis(IC, "MouseX", EInputAxis::AxisMouseX);
	BuildAxis(IC, "MouseY", EInputAxis::AxisMouseY);
}



void UInputBeacon::BuildKey(UInputComponent* IC, FName Key, TEnumAsByte<EInputKey> ID)
{
	UInputKey* InputKey = NewObject<UInputKey>();
	IC->BindKey(FKey(Key), IE_Pressed, InputKey, &UInputKey::Press);
	IC->BindKey(FKey(Key), IE_Released, InputKey, &UInputKey::Release);
	KeyMap.Add(ID, InputKey);
}

void UInputBeacon::BuildAxis(UInputComponent* IC, FName Key, TEnumAsByte<EInputAxis> ID)
{
	UInputAxis* InputAxis = NewObject<UInputAxis>();
	IC->BindAxisKey(FKey(Key), InputAxis, &UInputAxis::Axis);
	AxisMap.Add(ID, InputAxis);
}
*/