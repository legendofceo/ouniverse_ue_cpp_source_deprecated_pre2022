// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Delegate.generated.h"

DECLARE_DELEGATE(FDelBasic);
DECLARE_DELEGATE_OneParam(FDelBasicObject, UObject*);
DECLARE_DYNAMIC_DELEGATE(FDelDynamic);
DECLARE_DYNAMIC_DELEGATE_OneParam(FDelDynamicObject, UObject*, Object);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDelDynamicMulticast);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelMulticastInt, int, Int);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelMulticastByte, uint8, Byte);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelMulticastObj, UObject*, Object);

USTRUCT(BlueprintType)
struct FDelegateForceGenerated
{
	GENERATED_BODY()

public:

};