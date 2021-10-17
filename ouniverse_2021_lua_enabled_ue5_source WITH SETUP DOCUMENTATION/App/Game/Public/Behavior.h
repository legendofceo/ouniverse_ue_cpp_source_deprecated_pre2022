// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Behavior.generated.h"


UCLASS(Abstract)
class APP_API UBehavior : public UObject
{
	GENERATED_BODY()

public:

	virtual void Init();

	virtual void Connect();
	virtual void Disconnect();

};
