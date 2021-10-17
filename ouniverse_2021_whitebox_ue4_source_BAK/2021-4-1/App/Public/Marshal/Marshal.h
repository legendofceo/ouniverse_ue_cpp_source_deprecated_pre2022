// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Marshal.generated.h"


class MarshalObjectC;
class MarshalC;

USTRUCT(BlueprintType)
struct FMarshal
{
	GENERATED_BODY()

public:

	MarshalObjectC* M;

	FMarshal();

	FMarshal& Add(MarshalC* InM);

	MarshalObjectC* ToObject();

	FMarshal& AddBool(FString Key, bool* Ptr);
	FMarshal& AddInt(FString Key, int* Ptr);
	FMarshal& AddFloat(FString Key, float* Ptr);
	FMarshal& AddString(FString Key, FString* Ptr);
	FMarshal& AddObject(FString Key, FMarshal* Ptr);

};