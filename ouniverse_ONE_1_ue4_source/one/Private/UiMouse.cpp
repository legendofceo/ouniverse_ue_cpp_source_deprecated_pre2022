// Fill out your copyright notice in the Description page of Project Settings.


#include "UiMouse.h"
#include "APC.h"
#include "Components/CanvasPanel.h"
#include "Components/CanvasPanelSlot.h"
#include "Blueprint/WidgetLayoutLibrary.h"
#include "Components/NamedSlot.h"

void UUiMouse::NativeConstruct()
{
	PC = APC::GetPC();
	Style = CreateDefaultStyle();
	OuterSlot = Cast<UCanvasPanelSlot>(StyleSlot->Slot);
	StyleSlot->AddChild(Style);
	Super::NativeConstruct();	
}


void UUiMouse::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
	MousePosition = UWidgetLayoutLibrary::GetMousePositionOnViewport(PC);
	OuterSlot->SetPosition(MousePosition);
}


void UUiMouse::CenterMouse()
{
	FVector2D Center = UWidgetLayoutLibrary::GetViewportSize(PC) / 2;
	FViewport* v = CastChecked<ULocalPlayer>(PC->Player)->ViewportClient->Viewport;
	v->SetMouse(Center.X, Center.Y);
}