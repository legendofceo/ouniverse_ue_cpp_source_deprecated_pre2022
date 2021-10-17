// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Type/Json.h"
#include "Type/Array.h"
#include "Marshal.generated.h"



struct MarshalStateBoolS
{

public:

	bool V;
	FMarshalBool* P;

	MarshalStateBoolS();
};

USTRUCT(BlueprintType)
struct FMarshalBool
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Key;

	bool* Value;

	FMarshalBool();

	FMarshalBool(FString InKey, bool* InValue);

	MarshalStateBoolS GetState();
};

struct MarshalStateIntS
{

public:

	int V;
	FMarshalInt* P;

	MarshalStateIntS();
};

USTRUCT(BlueprintType)
struct FMarshalInt
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Key;

	int* Value;

	FMarshalInt();

	FMarshalInt(FString InKey, int* InValue);

	MarshalStateIntS GetState();
};

struct MarshalStateFloatS
{

public:

	float V;
	FMarshalFloat* P;

	MarshalStateFloatS();
};

USTRUCT(BlueprintType)
struct FMarshalFloat
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Key;

	float* Value;

	FMarshalFloat();

	FMarshalFloat(FString InKey, float* InValue);

	MarshalStateFloatS GetState();

};

struct MarshalStateStringS
{

public:

	FString V;
	FMarshalString* P;

	MarshalStateStringS();
};

USTRUCT(BlueprintType)
struct FMarshalString
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Key;

	FString* Value;

	FMarshalString();

	FMarshalString(FString InKey, FString* InValue);

	MarshalStateStringS GetState();

};

struct MarshalStateObjectS
{

public:

	FMarshal* P;
	
	ArrayC<MarshalStateBoolS> Bools;
	ArrayC<MarshalStateIntS> Ints;
	ArrayC<MarshalStateFloatS> Floats;
	ArrayC<MarshalStateStringS> Strings;
	ArrayC<MarshalStateObjectS> Objects;

	MarshalStateObjectS();
};

USTRUCT(BlueprintType)
struct FMarshalObject
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Key;

	FMarshal* P;

	FMarshalObject();

	FMarshalObject(FString InKey, FMarshal* InValue);


	MarshalStateObjectS GetState();
};

USTRUCT(BlueprintType)
struct FMarshal
{
	GENERATED_BODY()

public:
		

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	TArray<FMarshalBool> Bools;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FMarshalInt> Ints;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FMarshalFloat> Floats;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FMarshalString> Strings;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FMarshalObject> Objects;

	void RegBool(FString Key, bool* P);
	void RegInt(FString Key, int* P);
	void RegFloat(FString Key, float* P);
	void RegString(FString Key, FString* P);
	void RegObject(FString Key, FMarshal* P);

	JsonS Json();
};

USTRUCT(BlueprintType)
struct FMarshalHandle
{
	GENERATED_BODY()

public:

	FMarshal* P;

	FMarshalHandle()
	{
		P = NULL;
	}

	FMarshalHandle(FMarshal* InMarshalPtr)
	{
		P = InMarshalPtr;
	}
};

UCLASS()
class APP_API UMarshalUtil : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(Category = "Marshal", BlueprintCallable, meta = (DisplayName = "#MarshalDebugPrint"))
	static void MarshalDebugPrint(UPARAM(ref) FMarshalHandle& Handle);

	UFUNCTION(Category = "Marshal", BlueprintCallable, meta = (DisplayName = "#MarshalHandle"))
	static void MakeMarshalHandleBP(UPARAM(ref) FMarshal& Marshal, FMarshalHandle& Handle);

	UFUNCTION(Category = "Marshal", BlueprintCallable, meta = (DisplayName = "#MarshalBool"))
	static void RegMarshalBoolBP(UPARAM(ref) FMarshalHandle& Handle, FString Key, UPARAM(ref) bool& Bool, FMarshalHandle& HandleR);

	UFUNCTION(Category = "Marshal", BlueprintCallable, meta = (DisplayName = "#MarshalInt"))
	static void RegMarshalIntBP(UPARAM(ref) FMarshalHandle& Handle, FString Key, UPARAM(ref) int& Int, FMarshalHandle& HandleR);

	UFUNCTION(Category = "Marshal", BlueprintCallable, meta = (DisplayName = "#MarshalFloat"))
	static void RegMarshalFloatBP(UPARAM(ref) FMarshalHandle& Handle, FString Key, UPARAM(ref) float& Int, FMarshalHandle& HandleR);

	UFUNCTION(Category = "Marshal", BlueprintCallable, meta = (DisplayName = "#MarshalString"))
	static void RegMarshalStringBP(UPARAM(ref) FMarshalHandle& Handle, FString Key, UPARAM(ref) FString& Int, FMarshalHandle& HandleR);

	UFUNCTION(Category = "Marshal", BlueprintCallable, meta = (DisplayName = "#MarshalObject"))
	static void RegMarshalObjectBP(UPARAM(ref) FMarshalHandle& Handle, FString Key, UPARAM(ref) FMarshal& Object, FMarshalHandle& HandleR);

};