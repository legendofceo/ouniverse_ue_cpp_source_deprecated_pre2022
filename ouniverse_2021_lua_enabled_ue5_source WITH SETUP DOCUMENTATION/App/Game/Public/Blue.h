// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Blue.generated.h"

/**
 * 
 */

USTRUCT(BlueprintType)
struct FBlueEnsureImplementation
{
	GENERATED_BODY()

public:

	TArray<FName> FunctionNames;

	void Add(FName Name);

	bool Go(UObject* Obj, FString ID);
};

USTRUCT(BlueprintType)
struct FBlueTSubclassOfList
{
	GENERATED_BODY()

public:

	TArray<TSubclassOf<UObject>> Objects;

	void Add(TSubclassOf<UObject> Object);

	int Total = 0;

	bool HasNull();

};

UCLASS()
class APP_API UBlue : public UObject
{
	GENERATED_BODY()
	
};
