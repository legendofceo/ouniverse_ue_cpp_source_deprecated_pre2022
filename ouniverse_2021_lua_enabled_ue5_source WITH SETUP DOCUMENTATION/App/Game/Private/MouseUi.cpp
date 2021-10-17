// Fill out your copyright notice in the Description page of Project Settings.


#include "MouseUi.h"
#include "AppStream.h"
#include "AppController.h"
#include "Log.h"
#include "Components/CanvasPanel.h"
#include "Components/CanvasPanelSlot.h"

const FName UMouseUi::SYS = "MouseUi";

void UMouseUi::Init()
{
	if(DefaultDartSoft.IsNull())
	{
		LOG.S(SYS).T(TCRIT).W("DefaultDartSoft is null").DebugM();
		return;
	}

	SetActiveDart(DefaultDartSoft);
}

void UMouseUi::SetActiveDart(TSoftClassPtr<UUserWidget> DartSoft)
{
	UAppStream::Get()->Stream(DartSoft.ToSoftObjectPath(), FStreamableDelegate::CreateUObject(this, &UMouseUi::SetActiveDart_Stream, DartSoft));
}

void UMouseUi::SetActiveDart_Stream(TSoftClassPtr<UUserWidget> DartSoft)
{
	if (ActiveDart)
	{
		ActiveDart->RemoveFromParent();
	}

	ActiveDart = CreateWidget<UUserWidget>(this, DartSoft.Get());
	CanvasSlot = Canvas->AddChildToCanvas(ActiveDart);
	CanvasSlot->SetAutoSize(true);
}

void UMouseUi::Update(float MouseX, float MouseY)
{
	if (ActiveDart)
	{
		CanvasSlot->SetPosition(FVector2D(MouseX, MouseY));
	}

}


void UMouseUi::Show()
{
	AAppController::Get()->bShowMouseCursor = true;
	SetVisibility(ESlateVisibility::HitTestInvisible);
}

void UMouseUi::Hide()
{
	AAppController::Get()->bShowMouseCursor = false;
	SetVisibility(ESlateVisibility::Collapsed);
}