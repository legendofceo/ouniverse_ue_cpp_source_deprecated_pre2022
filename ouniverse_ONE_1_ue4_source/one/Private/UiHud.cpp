// Fill out your copyright notice in the Description page of Project Settings.


#include "UiHud.h"
#include "APC.h"


void UUiHud::NativeConstruct()
{
	PC = APC::GetPC();
	Super::NativeConstruct();
	bIsFocusable = false;
}


/**
void UUiHud::AuxModeStart()
{
	bIsFocusable = true;
	SetFocus();
	//ActivateMouse();
	//CenterMouse();
	SetVisibility(ESlateVisibility::Visible);
}

void UUiHud::AuxModeEnd()
{
	//DeactivateMouse();
	SetVisibility(ESlateVisibility::HitTestInvisible);
}
*/