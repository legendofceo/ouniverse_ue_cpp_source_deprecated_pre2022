// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Remote.h"
#include "CompanionRemote.generated.h"


class APlayerPort;

UCLASS(BlueprintType, Blueprintable)
class APP_API ACompanionRemote : public ARemote
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	ACompanionRemote();

};
