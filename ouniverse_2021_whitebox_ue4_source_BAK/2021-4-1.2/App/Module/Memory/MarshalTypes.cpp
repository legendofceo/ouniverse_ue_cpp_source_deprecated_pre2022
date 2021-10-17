// Fill out your copyright notice in the Description page of Project Settings.


#include "MarshalTypes.h"
#include "Json.h"

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


void UMarshalTypes::MarshalBoolBP(FMarshal& Marshal, FString Key, bool& Bool, FMarshal& MarshalR)
{
	MarshalR = Marshal.AddBool(Key, &Bool);
}



void UMarshalTypes::MarshalObjectBP(FMarshal& Marshal, FString Key, FMarshal& Object, FMarshal& MarshalR)
{
	MarshalPointerC* M = new MarshalPointerC(Key, Object.M);
	Marshal.M->Add(M);
	MarshalR = Marshal;
}






void UMarshalTypes::MarshalDebugPrint(FMarshal& Marshal)
{
	JsonS J = JsonS();
	Marshal.M->Json(J);
	FString SerializedJson = J.Serialize();
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green, SerializedJson);
}
