// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Pact.generated.h"


class UActraMem;

USTRUCT(Blueprintable, BlueprintType)
struct APP_API FPact
{
	GENERATED_BODY()

public:

	UPROPERTY(VisibleAnywhere)
	TArray<UActraMem*> ActraMems;

	UPROPERTY(VisibleAnywhere)
	int PlayerActraIndex = 0;

	void AddActra(UActraMem* InActra);


};