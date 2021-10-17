// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Reg.generated.h"

/**
 * 
 */

class UUiHudInteractive;
class UBehavior;

UCLASS(Blueprintable, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ONE_API UReg : public UActorComponent
{
	GENERATED_BODY()

public:

	UPROPERTY(Category = BP, EditAnywhere, BlueprintReadOnly)
	TSubclassOf<UBehavior> BehaviorTest;
};
