// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Marshal.h"
#include "Array.h"


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

class MarshalFloatC : public MarshalC
{

public:

	float* P;

	MarshalFloatC(FString Key, float* Float);

	virtual void Json(JsonS* J) override;
};

class MarshalStringC : public MarshalC
{

public:

	FString* P;

	MarshalStringC(FString Key, FString* String);

	virtual void Json(JsonS* J) override;
};