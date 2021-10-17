// Fill out your copyright notice in the Description page of Project Settings.


#include "control_link.h"
#include "stroke.h"
#include "control_ue.h"
#include "control_event.h"

void UInputListener::Constructor(UControlLink* InControlLink, int InPriority)
{
	ControlLink = InControlLink;
}


bool UInputListener::Execute(UStroke* Stroke)
{
	OnInput.Broadcast(Stroke);
	return Stroke->IsHandled();
}

UControlLink* UControlLink::CreateControlLink(FName InID)
{
	UControlLink* N = NewObject<UControlLink>();
	N->ID = InID;
	return N;
}


UInputListener* UControlLink::BindKeyboard(EStrokeKB StrokeKB, bool bBindOnRelease, int InPriority)
{
	UInputListener* Listener = NewObject<UInputListener>();
	Listener->Constructor(this, InPriority);
	AControlUE* Control = AControlUE::Get();
	Control->BindKeyboard(Listener,StrokeKB,!bBindOnRelease);
	Listeners.Add(Listener);
	return Listener;
}