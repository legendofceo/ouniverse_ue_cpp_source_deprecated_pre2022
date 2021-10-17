// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UObject/Object.h"
#include "Delegates\IDelegateInstance.h"
#include "control_list.h"
#include "control_link.generated.h"

class UStroke;
struct FControlEvent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnInputDelegate, UStroke*, Stroke);



/**
UControlLink connects any uobject to the PlayerController and allows it to register to receive input.
The purpose of the control link is to stack all registries in one place.
This allows for quick registering and unregistering of the entire stack of binds.
*/

UCLASS(BlueprintType)
class UInputListener : public UObject
{
	GENERATED_BODY()

public:

	void Constructor(UControlLink* InControlLink, int InPriority);

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	UControlLink* ControlLink;
	
	UPROPERTY(VisibleAnywhere)
	int Priority;
	
	UPROPERTY(VisibleAnywhere)
	bool bPaused;


	FControlEvent* Owner;

	UPROPERTY(BlueprintAssignable)
	FOnInputDelegate OnInput;

	bool Execute(UStroke* InStroke);
};

UCLASS(BlueprintType)
class UControlLink : public UObject
{
	GENERATED_BODY()

public:

	FName ID;

	TArray<UInputListener*> Listeners;

	UFUNCTION(BlueprintCallable)
	UInputListener* BindKeyboard(EStrokeKB StrokeKB, bool bBindOnRelease, int InPriotiry);

	UFUNCTION(BlueprintCallable)
	void Delete() {};

	UFUNCTION(BlueprintCallable)
	static UControlLink* CreateControlLink(FName InID);

};