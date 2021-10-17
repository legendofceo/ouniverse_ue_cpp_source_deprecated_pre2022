// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Index.generated.h"


USTRUCT(Blueprintable, BlueprintType)
struct APP_API FIndex
{
	GENERATED_BODY()

public:

	FIndex() {};

	FIndex(int Start, int Min, int Max);

	UPROPERTY(EditAnywhere)
	int Value = 0;

	UPROPERTY(EditAnywhere)
	int MinValue = 0;

	UPROPERTY(EditAnywhere)
	int MaxValue = 1;

	UPROPERTY(EditAnywhere)
	bool Clamp = false;

	void Set(int NewValue);

	int Get();
	void Push(bool bReverse);
	void Increment();
	void Decrement();

	FIndex& operator++() {
		Increment();
		return *this;
	}

	FIndex operator++(int) {
		FIndex temp = *this;
		++* this;
		return temp;
	}

	FIndex& operator--() {
		Decrement();
		return *this;
	}

	FIndex operator--(int) {
		FIndex temp = *this;
		--* this;
		return temp;
	}

};

UCLASS(BlueprintType)
class APP_API UIndexStatics : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "#Index: Push"))
	static void Push(UPARAM(ref) FIndex& Index, bool bReverse, int& R);

	UFUNCTION(BlueprintCallable,meta=(DisplayName="#Index: Increment"))
	static void Increment(UPARAM(ref) FIndex& Index, int& R);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "#Index: Decrement"))
	static void Decrement(UPARAM(ref) FIndex& Index, int& R);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "#Index: Set"))
	static void Set(UPARAM(ref) FIndex& Index, int Value, int& R);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "#Index: SetMax"))
	static void SetMax(UPARAM(ref) FIndex& Index, int NewMax);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "#Index: Get"))
	static void Get(UPARAM(ref) FIndex& Index, int& R);

};