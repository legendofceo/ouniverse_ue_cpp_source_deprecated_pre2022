// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SoftServe.generated.h"

/**
 * 
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateSoftServe, USoftServe*, SoftServe);

UCLASS()
class APP_API USoftServe : public UObject
{
	GENERATED_BODY()

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TArray<TSoftClassPtr<UObject>> SoftClasses;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TArray<TSoftObjectPtr<UObject>> SoftObjects;


	void Add(TSoftClassPtr<UObject> SCP);
	void Add(TSoftObjectPtr<UObject> SOP);

	void Stream();

	bool NullCheck();

	void Complete();

	UPROPERTY(BlueprintAssignable)
	FDelegateSoftServe OnComplete;

};
