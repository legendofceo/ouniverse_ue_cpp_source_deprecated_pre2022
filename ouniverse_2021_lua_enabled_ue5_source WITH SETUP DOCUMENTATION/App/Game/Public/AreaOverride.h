// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AreaOverride.generated.h"

class UArea;

UCLASS()
class APP_API UAreaOverride : public UObject
{
	GENERATED_BODY()

public:

	bool IsActive();
};
