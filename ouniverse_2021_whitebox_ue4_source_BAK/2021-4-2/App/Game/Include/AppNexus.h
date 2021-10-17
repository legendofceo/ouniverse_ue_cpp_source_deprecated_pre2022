// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Nexus.h"
#include "AppNexus.generated.h"

class UApp;

UCLASS()
class APP_API AAppNexus : public ANexus
{
	GENERATED_BODY()

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UApp* App;

	void BeginPlay() override;
};
