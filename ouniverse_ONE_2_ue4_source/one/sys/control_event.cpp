// Fill out your copyright notice in the Description page of Project Settings.


#include "control_event.h"
#include "control_link.h"
#include "control_ue.h"
#include "stroke.h"


void UControlEventTrigger::Constructor(FControlEvent* InEvent)
{
	Event = InEvent;
}

void UControlEventTrigger::Pressed()
{
	Event->Pressed();
}

void UControlEventTrigger::Released()
{
	Event->Released();
}



void FControlEvent::Constructor(FControlButton* InButton, bool InIsDown)
{
	Button = InButton;
	bIsDown = InIsDown;
	Trigger = NewObject<UControlEventTrigger>();
	Trigger->Constructor(this);
}

void FControlEvent::AddListener(UInputListener* InListener)
{
	Listeners.Add(InListener);
	InListener->Owner = this;
	Num++;
}

UStroke* FControlEvent::CreateStroke()
{
	UStroke* Stroke = NewObject<UStroke>();
	return Stroke;
}

void FControlEvent::Pressed()
{
	UStroke* Stroke = CreateStroke();
	Button->bIsPressed = true;
	Stroke->bPressed = true;
	Button->LastEvent = AControlUE::Get()->GetWorld()->GetTimeSeconds();
	Broadcast(Stroke);
}

void FControlEvent::Released()
{
	UStroke* Stroke = CreateStroke();
	Button->bIsPressed = false;
	Stroke->bPressed = false;

	Stroke->StrokeID = Button->StrokeID + 1;
	Broadcast(Stroke);
}

void FControlEvent::Broadcast(UStroke* Stroke)
{

	for (int i = 0; i < Num; i++)
	{
		if (Listeners[i]->Execute(Stroke))
		{
			break;
		}
	}
}

void FControlButton::Constructor(AControlUE* InControl, FString InID, int InStrokeID)
{
	Control = InControl;
	ID = InID;
	StrokeID = InStrokeID;
	Up.Constructor(this,false);
	Down.Constructor(this,true);
}

void FControlButton::AddListener(UInputListener* Listener, bool bDown)
{
	if (bDown)
	{
		Down.AddListener(Listener);
	}
	else
	{
		Up.AddListener(Listener);
	}
}