// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "AppBae.generated.h"

class UMythBae;


UCLASS()
class APP_API AAppBae : public APlayerState
{
	GENERATED_BODY()

	AAppBae();

public:

	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UMythBae* MythBae;

};
