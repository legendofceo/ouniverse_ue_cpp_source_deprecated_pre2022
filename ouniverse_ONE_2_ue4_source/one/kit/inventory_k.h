// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Components/ActorComponent.h"
#include "UObject/SoftObjectPtr.h"
#include "inventory_k.generated.h"


USTRUCT()
struct FInventoryItem
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere)
	int item;
	UPROPERTY(EditAnywhere)
	int looted_flag;
	UPROPERTY(EditAnywhere)
	int death_only;

	FInventoryItem()
	{
	  
	}
};

UCLASS(Blueprintable, BlueprintType, config = Game)
class UInventoryK : public UActorComponent
{
	GENERATED_BODY()

public:

	UInventoryK();

	UPROPERTY(EditAnywhere)
	TArray<FInventoryItem> Perm;

};