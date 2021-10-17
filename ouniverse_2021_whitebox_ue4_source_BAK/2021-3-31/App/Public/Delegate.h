// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Delegate.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateObj, UObject*, Object);

USTRUCT(BlueprintType)
struct FDelegateForceGenerated
{
	GENERATED_BODY()
};