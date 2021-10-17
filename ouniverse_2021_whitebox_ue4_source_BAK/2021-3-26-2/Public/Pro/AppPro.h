// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Pro.h"
#include "AppPro.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class APP_API UAppPro : public UPro
{
	GENERATED_BODY()


public:

	UAppPro();

	virtual void BeginPlay() override;

};
