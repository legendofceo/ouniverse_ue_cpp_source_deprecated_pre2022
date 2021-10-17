// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Remote.h"
#include "CompanionRemote.generated.h"


class AAppController;

UCLASS(BlueprintType, Blueprintable)
class APP_API UCompanionRemote : public URemote
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UCompanionRemote();

	void Init(AAppController* AP);

};
