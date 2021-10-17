// Fill out your copyright notice in the Description page of Project Settings.


#include "Marshal.h"
#include "MarshalTypes.h"

FMarshal::FMarshal()
{
	M = new MarshalObjectC();
}


FMarshal& FMarshal::Add(MarshalC* InM)
{
	M->Add(InM);
	return *this;
}

FMarshal& FMarshal::AddBool(FString Key, bool* Ptr)
{
	MarshalBoolC* NewMarshal = new MarshalBoolC(Key, Ptr);
	M->Add(NewMarshal);
	return *this;
}

FMarshal& FMarshal::AddInt(FString Key, int* Ptr)
{
	MarshalIntC* NewMarshal = new MarshalIntC(Key, Ptr);
	M->Add(NewMarshal);
	return *this;
}

FMarshal& FMarshal::AddFloat(FString Key, float* Ptr)
{
	MarshalFloatC* NewMarshal = new MarshalFloatC(Key, Ptr);
	M->Add(NewMarshal);
	return *this;
}

FMarshal& FMarshal::AddString(FString Key, FString* Ptr)
{
	MarshalStringC* NewMarshal = new MarshalStringC(Key, Ptr);
	M->Add(NewMarshal);
	return *this;
}

FMarshal& FMarshal::AddObject(FString Key, FMarshal* Ptr)
{
	MarshalPointerC* NewMarshal = new MarshalPointerC(Key, ToObject());
	M->Add(NewMarshal);
	return *this;
}

MarshalObjectC* FMarshal::ToObject()
{
	return M;
}