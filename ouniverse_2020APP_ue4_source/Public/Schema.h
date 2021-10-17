// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ControlComponent.h"
#include "InterfaceInput.h"
#include "Schema.generated.h"

/**
 * 
 */



class AActra;

UCLASS(Blueprintable, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ETREIAAPP_API USchema : public UActorComponent
{
	GENERATED_BODY()

		
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	AActra* Actra;
};
