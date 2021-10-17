// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Bae.h"
#include "MythBae.generated.h"



UCLASS(BlueprintType, Blueprintable)
class APP_API UMythBae : public UBae
{
	GENERATED_BODY()

public:

	UMythBae();

	void Init();

	virtual void BeginPlay() override;

};
