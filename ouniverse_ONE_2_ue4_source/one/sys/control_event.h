// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UObject/Object.h"
#include "control_list.h"
#include "control_event.generated.h"

struct FControlEvent;
struct FControlEventListener;
class IControlInterface;
class UControlLink;
class UInputListener;
class UStroke;
class AControlUE;

/**
Listeners are placed on the control event but a pointer is kept also on the specific ControlLink created by a UObject.
ControLEvents trigger the listeners but the creater object change priority, pause state and unregister from their pointer to the listener held in the ControlLink.
*/

USTRUCT(BlueprintType)
struct FControlEventListener
{
	GENERATED_BODY()


public:

	FControlEventListener()
	{

	};

	UPROPERTY(VisibleAnywhere)
	UControlLink* Link;

	FControlEvent* Owner;
	UPROPERTY(VisibleAnywhere)
	FString Nickname;
	UPROPERTY(VisibleAnywhere)
	int Priority;
	UPROPERTY(VisibleAnywhere)
	bool bPaused;
	UPROPERTY(VisibleAnywhere)
	TEnumAsByte<EStrokeSpecial> Special;

	FControlEventListener(UControlLink* InLink,FString InNickname, int InPriority, EStrokeSpecial InSpecial)
	{
		Link = InLink;
		Nickname = InNickname;
		Priority = InPriority;
		Special = InSpecial;
	}

	bool Execute(UStroke* Stroke);

	//void SetPriority(int InPriority);
	//bool Execute();
};




/**
Trigger is a work around to have a nice display in the UE4 Editor as a struct.
The Trigger was needed to give a UFUNCTION for the dynamic delegate in the PlayerControl to trigger on keypress.
*/

UCLASS()
class UControlEventTrigger : public UObject
{
	GENERATED_BODY()


public:

	FControlEvent* Event;

	void Constructor(FControlEvent* InBeacon);

	UFUNCTION()
		void Pressed();
	UFUNCTION()
		void Released();

};


/**
The beacon is held on the playercontrol.
Each official keypress (including up and down variations) get a beacon.
Any uobject can subscribe to a beacon. 
When the beacon is triggered a paired interface function is triggered on the uobject in both C++ and blueprints.
*/

USTRUCT()
struct FControlEvent
{
	GENERATED_BODY()


public:

	void Constructor(FControlButton* InButton, bool InIsDown);

	UPROPERTY(VisibleAnywhere)
	int Num;
	UPROPERTY(VisibleAnywhere)
	TArray<UInputListener*> Listeners;
	UPROPERTY(VisibleAnywhere)
	bool Paused;
	
	UPROPERTY(VisibleAnywhere)
	bool bIsDown;

	FControlButton* Button;

	UPROPERTY(VisibleAnywhere)
	UControlEventTrigger* Trigger;

	void AddListener(UInputListener* InListener);

	UStroke* CreateStroke();

	void Pressed();
	void Released();
	
	void Broadcast(UStroke* Stroke);

};

USTRUCT()
struct FControlButton
{
	GENERATED_BODY()


public:

	void Constructor(AControlUE* InControl, FString InID, int InStrokeID);

	UPROPERTY(VisibleAnywhere)
	AControlUE* Control;

	UPROPERTY(VisibleAnywhere)
	FControlEvent Up;
	UPROPERTY(VisibleAnywhere)
	FControlEvent Down;

	UPROPERTY(VisibleAnywhere)
	int StrokeID;

	UPROPERTY(VisibleAnywhere)
	float LastEvent;

	UPROPERTY(VisibleAnywhere)
	bool bIsPressed;

	UPROPERTY(VisibleAnywhere)
	FString ID;
	UPROPERTY(VisibleAnywhere)
	bool Paused;	

	void AddListener(UInputListener* Listener, bool bDown);

};