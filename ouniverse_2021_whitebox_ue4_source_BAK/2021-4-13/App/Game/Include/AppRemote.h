// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Remote.h"
#include "AppRemote.generated.h"


UCLASS(BlueprintType, Blueprintable)
class APP_API UAppRemote : public URemote
{
	GENERATED_BODY()

public:

	UAppRemote();

	void BeginPlay() override;
};
