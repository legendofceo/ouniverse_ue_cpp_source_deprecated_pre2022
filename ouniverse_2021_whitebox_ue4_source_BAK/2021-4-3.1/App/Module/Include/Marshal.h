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


UCLASS()
class APP_API UMarshalUtil : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(Category = "Marshal", BlueprintCallable, meta = (DisplayName = "#MarshalNewDebugPrint"))
	static void MarshalDebugPrint(UPARAM(ref) FMarshal& Marshal);

	UFUNCTION(Category = "Marshal", BlueprintCallable, meta = (DisplayName = "#MarshalBool"))
	static void MarshalBoolBP(UPARAM(ref) FMarshal& Marshal, FString Key, UPARAM(ref) bool& Bool, FMarshal& MarshalR);

	UFUNCTION(Category = "Marshal", BlueprintCallable, meta = (DisplayName = "#MarshalObject"))
	static void MarshalObjectBP(UPARAM(ref) FMarshal& Marshal, FString Key, UPARAM(ref) FMarshal& Object, FMarshal& MarshalR);

};
