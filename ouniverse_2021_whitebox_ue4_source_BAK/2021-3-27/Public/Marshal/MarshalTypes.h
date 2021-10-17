// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Marshal/Marshal.h"
#include "Type/Array.h"
#include "MarshalTypes.generated.h"


struct JsonS;

class MarshalC
{
public:

	virtual ~MarshalC() {};
	FString Key;

	virtual void Json(JsonS* J) {};
};

class MarshalObjectC : public MarshalC
{
public:

	MarshalObjectC() {};

	ArrayC<MarshalC*> Marshals;

	void Add(MarshalC* M);

	void Json(JsonS* J);
};

class MarshalPointerC : public MarshalC
{
public:

	MarshalPointerC(FString InKey, MarshalC* InP);

	MarshalC* P;

	void Json(JsonS* J);
};

class MarshalBoolC : public MarshalC
{

public:

	bool* P;

	MarshalBoolC(FString Key, bool* Bool);

	virtual void Json(JsonS* J) override;
};

class MarshalIntC : public MarshalC
{

public:

	int* P;

	MarshalIntC(FString Key, int* Int);

	virtual void Json(JsonS* J) override;
};

UCLASS()
class APP_API UMarshalTypes : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(Category = "Marshal", BlueprintCallable, meta = (DisplayName = "#MarshalNewDebugPrint"))
	static void MarshalDebugPrint(UPARAM(ref) FMarshalNew& Marshal);

	UFUNCTION(Category = "Marshal", BlueprintCallable, meta = (DisplayName = "#MarshalBool"))
	static void MarshalBoolBP(UPARAM(ref) FMarshalNew& Marshal, FString Key, UPARAM(ref) bool& Bool, FMarshalNew& MarshalR);

	UFUNCTION(Category = "Marshal", BlueprintCallable, meta = (DisplayName = "#MarshalObject"))
	static void MarshalObjectBP(UPARAM(ref) FMarshalNew& Marshal, FString Key, UPARAM(ref) FMarshalNew& Object, FMarshalNew& MarshalR);

};
