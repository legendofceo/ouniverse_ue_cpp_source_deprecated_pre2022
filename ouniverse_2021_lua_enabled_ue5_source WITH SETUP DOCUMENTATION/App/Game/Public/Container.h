// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Container.generated.h"

class UItemOld;

UCLASS(BlueprintType, Blueprintable)
class APP_API UContainer: public UObject
{
	GENERATED_BODY()

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int MemKey = 0;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	int MemType = 0;

};