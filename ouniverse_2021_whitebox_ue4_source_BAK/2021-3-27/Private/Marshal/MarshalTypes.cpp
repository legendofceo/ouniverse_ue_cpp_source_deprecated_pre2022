// Fill out your copyright notice in the Description page of Project Settings.


#include "Marshal/MarshalTypes.h"
#include "Type/Json.h"

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




void UMarshalTypes::MarshalBoolBP(FMarshalNew& Marshal, FString Key, bool& Bool, FMarshalNew& MarshalR)
{
	MarshalBoolC* M = new MarshalBoolC(Key,&Bool);
	Marshal.M->Add(M);
	MarshalR = Marshal;
}


void UMarshalTypes::MarshalObjectBP(FMarshalNew& Marshal, FString Key, FMarshalNew& Object, FMarshalNew& MarshalR)
{
	MarshalPointerC* M = new MarshalPointerC(Key, Object.M);
	Marshal.M->Add(M);
	MarshalR = Marshal;
}






void UMarshalTypes::MarshalDebugPrint(FMarshalNew& Marshal)
{
	JsonS J = JsonS();
	Marshal.M->Json(J);
	FString SerializedJson = J.Serialize();
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green, SerializedJson);
}
