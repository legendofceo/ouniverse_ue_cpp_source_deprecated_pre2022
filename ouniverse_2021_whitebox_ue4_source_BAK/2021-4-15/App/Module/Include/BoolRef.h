// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BoolRef.generated.h"

/**
 *
 */

USTRUCT(BlueprintType)
struct FBoolRef
{
	GENERATED_BODY()

public:

	bool* P = NULL;


	FBoolRef()
	{
		P = NULL;
	}

	FBoolRef(bool& InP)
	{
		P = &InP;
	}

	bool Get()
	{
		return *P;
	}

};

UCLASS()
class APP_API UBoolRefUtil : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(Category = "Bool", BlueprintCallable, meta = (DisplayName = "#RefBool"))
	static void SetBool(UPARAM(ref) FBoolRef& Bool, bool Value)
	{
		*Bool.P = Value;
	}


};