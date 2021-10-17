// Fill out your copyright notice in the Description page of Project Settings.


#include "NotificationUi.h"
#include "AppStream.h"
#include "Components/CanvasPanel.h"
#include "Components/CanvasPanelSlot.h"

void UNotificationUi::Open(const FDelBasic& Callback)
{
	OnComplete = Callback;
	GetWorld()->GetTimerManager().SetTimer(Timer, this, &UNotificationUi::Close, DisplayTime, true);
	BeginOpen();
}

void UNotificationUi::Close()
{
	BeginClose();
}

void UNotificationUi::BeginClose_Implementation()
{
	CloseComplete();
}

void UNotificationUi::CloseComplete()
{
	RemoveFromParent();
	OnComplete.Execute();
}

void UNotificationWin::AddNotification(TSoftClassPtr<UNotificationUi> NotificationSoft)
{
	UAppStream::Get()->Stream(NotificationSoft.ToSoftObjectPath(), FStreamableDelegate::CreateUObject(this, &UNotificationWin::AddNotification_Stream, NotificationSoft));
}

void UNotificationWin::AddNotification_Stream(TSoftClassPtr<UNotificationUi> NotificationSoft)
{
	UNotificationUi* Notification = CreateWidget<UNotificationUi>(this, NotificationSoft.Get());
	AddToQue(Notification);
}


void UNotificationWin::AddToQue(UNotificationUi* Notification)
{
	Notifications.Add(Notification);

	if (!bDisplayingNotification)
	{
		ShowNextNotification();
	}
}

void UNotificationWin::ShowNextNotification()
{
	bDisplayingNotification = true;
	UNotificationUi* Next = Notifications[0];
	Notifications.RemoveAt(0);
	UCanvasPanelSlot* CanvasSlot = NotificationPin->AddChildToCanvas(Next);
	CanvasSlot->SetAutoSize(true);
	CanvasSlot->SetAnchors(FAnchors(1.0,0.5,1.0,0.5));
	CanvasSlot->SetAlignment(FVector2D(1,0.5));
	FDelBasic Callback;
	Callback.BindUObject(this, &UNotificationWin::NotificationComplete);
	Next->Open(Callback);
}

void UNotificationWin::NotificationComplete()
{
	bDisplayingNotification = false;
	if (Notifications.Num() > 0)
	{
		ShowNextNotification();
	}
}