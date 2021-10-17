// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/SoftObjectPtr.h"
#include "base.h"
#include "log.h"
#include "area_manager.generated.h"


UCLASS()
class AAreaManager : public ABase
{

	GENERATED_BODY()

public:

	AAreaManager();
	static AAreaManager* Get();
	static AAreaManager* Create(AActor* WorldActor);
	void Constructor();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FLogger Log;


	bool ChangePrimaryArea();

};