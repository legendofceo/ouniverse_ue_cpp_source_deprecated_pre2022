//Copyright 2015-2019, All Rights Reserved.

#include "Ui/Ui.h"
#include "App/Scope.h"
#include "App/Reg.h"

#include "Components/CanvasPanel.h"
#include "Components/CanvasPanelSlot.h"


namespace GlobalUi
{
	UUi* Object;
}

UUi* UUi::Create()
{
		UUi* Neu = CreateWidget<UUi>(ScopeC::World(), UReg::Get()->UiClass);
		GlobalUi::Object = Neu;
		Neu->AddToViewport();
		return Neu;
}

UUi* UUi::Get()
{
	return GlobalUi::Object;
}


void UUi::ToViewport(UWidget* InWidget)
{
	Viewport->AddChildToCanvas(InWidget);
	UCanvasPanelSlot* CanvasSlot = Cast<UCanvasPanelSlot>(InWidget->Slot);
	CanvasSlot->SetAnchors(FAnchors(0.0f, 0.0f, 1.0f, 1.0f));
	CanvasSlot->SetOffsets(FMargin(0.0f,0.0f,0.0f,0.0f));
}

void UUi::ToShelf(UWidget* InWidget)
{
	Shelf->AddChildToCanvas(InWidget);
	UCanvasPanelSlot* CanvasSlot = Cast<UCanvasPanelSlot>(InWidget->Slot);
	CanvasSlot->SetAnchors(FAnchors(0.0f, 0.0f, 1.0f, 1.0f));
	CanvasSlot->SetOffsets(FMargin(0.0f, 0.0f, 0.0f, 0.0f));
	CanvasSlot->SetAutoSize(true);
}

void UUi::ToTray(UWidget* InWidget)
{
	Tray->AddChildToCanvas(InWidget);
	UCanvasPanelSlot* CanvasSlot = Cast<UCanvasPanelSlot>(InWidget->Slot);
	CanvasSlot->SetAnchors(FAnchors(0.0f, 0.0f, 1.0f, 1.0f));
	CanvasSlot->SetOffsets(FMargin(0.0f, 0.0f, 0.0f, 0.0f));
	CanvasSlot->SetAutoSize(true);
}