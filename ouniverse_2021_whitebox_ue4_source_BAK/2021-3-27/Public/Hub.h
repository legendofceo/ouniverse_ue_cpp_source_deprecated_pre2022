// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Info.h"
#include "Hub.generated.h"


class ACompanionActor;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class APP_API AHub : public AInfo
{
	GENERATED_BODY()

public:

	AHub();
};
