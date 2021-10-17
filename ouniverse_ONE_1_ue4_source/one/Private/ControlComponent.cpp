// Fill out your copyright notice in the Description page of Project Settings.


#include "ControlComponent.h"
#include "Actra.h"
#include "Input.h"
#include "APC.h"


void UControlComponent::BindComplex()
{
	APC* APC = APC::GetPC();
	

	//APC->InputComponent->BindKey(FKey(KB->PadABind), IE_Pressed, this, &UControlComponent::PadA_Pressed);
	//APC->InputComponent->BindKey(FKey(KB->PadABind), IE_Pressed, this, &UControlComponent::PadA_Pressed);
	//APC->InputComponent->BindKey(FKey(KB->PadABind), IE_Released, this, &UControlComponent::PadA_Released);
	//APC->InputComponent->BindKey(FKey(KB->PadBBind), IE_Pressed, this, &UControlComponent::PadB_Pressed);
	//APC->InputComponent->BindKey(FKey(KB->PadBBind), IE_Released, this, &UControlComponent::PadB_Released);
	//APC->InputComponent->BindKey(FKey(KB->PadXBind), IE_Pressed, this, &UControlComponent::PadX_Pressed);
	//APC->InputComponent->BindKey(FKey(KB->PadXBind), IE_Released, this, &UControlComponent::PadX_Released);
	//APC->InputComponent->BindKey(FKey(KB->PadYBind), IE_Pressed, this, &UControlComponent::PadY_Pressed);
	//APC->InputComponent->BindKey(FKey(KB->PadYBind), IE_Released, this, &UControlComponent::PadY_Released);

	//IC->BindKey(FKey(Key), IE_Released, InputKey, &UInputKey::Release);
	//Actra = Cast<AActra>(GetOwner());
	//Super::BeginPlay();
}

void UControlComponent::PadA_Pressed()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("A"));
	OnPadExPressed.Broadcast();
}

void UControlComponent::PadA_Released()
{
	OnPadExReleased.Broadcast();
}

void UControlComponent::PadB_Pressed()
{
	OnPadCirclePressed.Broadcast();
}

void UControlComponent::PadB_Released()
{
	OnPadCircleReleased.Broadcast();
}

void UControlComponent::PadX_Pressed()
{
	OnPadSquarePressed.Broadcast();
}

void UControlComponent::PadX_Released()
{
	OnPadSquareReleased.Broadcast();
}

void UControlComponent::PadY_Pressed()
{
	OnPadTrianglePressed.Broadcast();
}

void UControlComponent::PadY_Released()
{
	OnPadTriangleReleased.Broadcast();
}