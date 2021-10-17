// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Pro.h"
#include "WorldPro.generated.h"


class UInputButtonEvent;


UCLASS(BlueprintType, Blueprintable)
class APP_API UWorldPro : public UPro
{
	GENERATED_BODY()

public:


	virtual void BeginPlay() override;


	void Start();

	void ConnectToPartySlot();

	void HoverNextPartySlot() {};

	void ObservePartySlot() {};

//Input
public: 

	void RouteBT(UInputButtonEvent* BT) {};
	void RouteAX(UInputButtonEvent* AX) {};
	void RouteEV(UInputButtonEvent* EV) {};

};
