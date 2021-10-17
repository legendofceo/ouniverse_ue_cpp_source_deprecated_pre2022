// Fill out your copyright notice in the Description page of Project Settings.


#include "MarshalTypes.h"
#include "json+.h"

void MarshalObjectC::Add(MarshalC* M)
{
	Marshals.Add(M);
}

void MarshalObjectC::Json(JsonS* J)
{

	int L = Marshals.Len();

	for (int i = 0; i < L; i++)
	{
		Marshals[i]->Json(J);
	}
}


MarshalPointerC::MarshalPointerC(FString InKey, MarshalC* InP)
{
	Key = InKey;
	P = InP;
}

void MarshalPointerC::Json(JsonS* J)
{
	P->Json(J);
}

MarshalBoolC::MarshalBoolC(FString InKey, bool* Bool)
{
	Key = InKey;
	P = Bool;
}

void MarshalBoolC::Json(JsonS* J)
{

	int Result = 0;
	bool Value = *P;

	if (Value == true)
	{
		Result = 1;
	}
	
	J->Add(TCHAR_TO_UTF8(*Key), Result);

}

MarshalIntC::MarshalIntC(FString InKey, int* Int)
{
	Key = InKey;
	P = Int;
}

void MarshalIntC::Json(JsonS* J)
{
	J->Add(TCHAR_TO_UTF8(*Key), *P);
}

MarshalFloatC::MarshalFloatC(FString InKey, float* Float)
{
	Key = InKey;
	P = Float;
}

void MarshalFloatC::Json(JsonS* J)
{
	J->Add(TCHAR_TO_UTF8(*Key), *P);
}

MarshalStringC::MarshalStringC(FString InKey, FString* String)
{
	Key = InKey;
	P = String;
}

void MarshalStringC::Json(JsonS* J)
{
	J->Add(TCHAR_TO_UTF8(*Key), *P);
}