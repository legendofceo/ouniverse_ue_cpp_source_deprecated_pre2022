// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Components/ActorComponent.h"
#include "UObject/SoftObjectPtr.h"
#include "equipslot.generated.h"



UCLASS(Blueprintable, BlueprintType, config = Game)
class UEquipSlot : public UActorComponent
{
	GENERATED_BODY()

public:

	UEquipSlot();

};