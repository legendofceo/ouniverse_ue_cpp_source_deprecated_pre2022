// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Components/ActorComponent.h"
#include "../sys/data_address.h"
#include "data_k.generated.h"



UCLASS(Blueprintable, BlueprintType, config = Game)
class UDataK: public UActorComponent
{
	GENERATED_BODY()

public:

	UDataK();

	UPROPERTY(EditAnywhere)
	FDataAddress DataAddress;

};