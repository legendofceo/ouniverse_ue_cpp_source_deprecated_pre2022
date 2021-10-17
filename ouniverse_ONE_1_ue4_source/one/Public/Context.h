// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Context.generated.h"

UCLASS()
class ONE_API UContext : public UObject
{
	GENERATED_BODY()

public:

	static UObject* Get();
};
