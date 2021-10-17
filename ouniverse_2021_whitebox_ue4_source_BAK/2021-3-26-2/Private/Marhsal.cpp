// Fill out your copyright notice in the Description page of Project Settings.


#include "Marshal.h"


MarshalStateBoolS::MarshalStateBoolS()
{
	P = NULL;
	V = false;
}


FMarshalBool::FMarshalBool()
{
	Key = "$ERROR";
	Value = NULL;
}

FMarshalBool::FMarshalBool(FString InKey, bool* InValue)
{
	Key = InKey;
	Value = InValue;
}

MarshalStateBoolS FMarshalBool::GetState()
{
	MarshalStateBoolS State = MarshalStateBoolS();
	State.P = this;
	State.V = *Value;
	return State;
}

MarshalStateIntS::MarshalStateIntS()
{
	P = NULL;
	V = false;
}


FMarshalInt::FMarshalInt()
{
	Key = "$ERROR";
	Value = 0;
}

FMarshalInt::FMarshalInt(FString InKey, int* InValue)
{
	Key = InKey;
	Value = InValue;
}

MarshalStateIntS FMarshalInt::GetState()
{
	MarshalStateIntS State = MarshalStateIntS();
	State.P = this;
	State.V = *Value;
	return State;
}

MarshalStateFloatS::MarshalStateFloatS()
{
	P = NULL;
	V = false;
}

FMarshalFloat::FMarshalFloat()
{
	Key = "$ERROR";
	Value = NULL;

}

FMarshalFloat::FMarshalFloat(FString InKey, float* InValue)
{
	Key = InKey;
	Value = InValue;
}

MarshalStateFloatS FMarshalFloat::GetState()
{
	MarshalStateFloatS State = MarshalStateFloatS();
	State.P = this;
	State.V = *Value;
	return State;
}

MarshalStateStringS::MarshalStateStringS()
{
	P = NULL;
	V = false;
}

FMarshalString::FMarshalString()
{
	Key = "$ERROR";
	Value = NULL;

}


FMarshalString::FMarshalString(FString InKey, FString* InValue)
{
	Key = InKey;
	Value = InValue;
}

MarshalStateStringS FMarshalString::GetState()
{
	MarshalStateStringS State = MarshalStateStringS();
	State.P = this;
	State.V = *Value;
	return State;
}

MarshalStateObjectS::MarshalStateObjectS()
{
	P = NULL;
}

FMarshalObject::FMarshalObject()
{
	Key = "$ERROR";
	P = NULL;

}

FMarshalObject::FMarshalObject(FString InKey, FMarshal* InValue)
{
	Key = InKey;
	P = InValue;
}

MarshalStateObjectS FMarshalObject::GetState()
{
	MarshalStateObjectS State = MarshalStateObjectS();
	State.P = P;
	//State.V = *P;
	return State;
}

void FMarshal::RegBool(FString Key, bool* P)
{
	FMarshalBool M = FMarshalBool(Key,P);
	Bools.Add(M);
}

void FMarshal::RegInt(FString Key, int* P)
{
	FMarshalInt M = FMarshalInt(Key, P);
	Ints.Add(M);
}

void FMarshal::RegFloat(FString Key, float* P)
{
	FMarshalFloat M = FMarshalFloat(Key, P);
	Floats.Add(M);
}

void FMarshal::RegString(FString Key, FString* P)
{
	FMarshalString M = FMarshalString(Key, P);
	Strings.Add(M);
}


void FMarshal::RegObject(FString Key, FMarshal* P)
{
	FMarshalObject M = FMarshalObject(Key, P);
	Objects.Add(M);
}

JsonS FMarshal::Json()
{
	JsonS J = JsonS();

	int Result;
	for (FMarshalBool MBool : Bools)
	{
		Result = 0;
		bool Value = *MBool.Value;
		if (Value==true)
		{
			Result = 1;
		}
		J.Add(TCHAR_TO_UTF8(*MBool.Key), Result);
	}


	for (FMarshalInt MInt : Ints)
	{
		//const int P = *MInt.P;
		J.Add(TCHAR_TO_UTF8(*MInt.Key), *MInt.Value);
	}

	for (FMarshalFloat MFloat : Floats)
	{
		//const int P = *MFloat.P;
		J.Add(TCHAR_TO_UTF8(*MFloat.Key), *MFloat.Value);
	}

	for (FMarshalString MString : Strings)
	{
		//const FString P = *MString.P;
		J.Add(TCHAR_TO_UTF8(*MString.Key), *MString.Value);
	}

	for (FMarshalObject MObject : Objects)
	{
		//const FString P = *MString.P;
		J.Add(TCHAR_TO_UTF8(*MObject.Key), MObject.P->Json());
	}

	return J;
}

void UMarshalUtil::MarshalDebugPrint(UPARAM(ref) FMarshalHandle& Handle)
{
	FString SerializedJson = Handle.P->Json().Serialize();
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green, SerializedJson);
}

void UMarshalUtil::MakeMarshalHandleBP(FMarshal& Marshal, FMarshalHandle& Handle)
{
	FMarshalHandle MarshalHandle = FMarshalHandle(&Marshal);
	Handle = MarshalHandle;
}

void UMarshalUtil::RegMarshalBoolBP(FMarshalHandle& Handle, FString Key, bool& Bool, FMarshalHandle& HandleR)
{
	Handle.P->RegBool(Key, &Bool);
	HandleR = Handle;
}

void UMarshalUtil::RegMarshalIntBP(FMarshalHandle& Handle, FString Key, int& Int, FMarshalHandle& HandleR)
{
	Handle.P->RegInt(Key, &Int);
	HandleR = Handle;
}

void UMarshalUtil::RegMarshalFloatBP(FMarshalHandle& Handle, FString Key, float& Float, FMarshalHandle& HandleR)
{
	Handle.P->RegFloat(Key, &Float);
	HandleR = Handle;
}

void UMarshalUtil::RegMarshalStringBP(FMarshalHandle& Handle, FString Key, FString& String, FMarshalHandle& HandleR)
{
	Handle.P->RegString(Key, &String);
	HandleR = Handle;
}

void UMarshalUtil::RegMarshalObjectBP(FMarshalHandle& Handle, FString Key, FMarshal& Object, FMarshalHandle& HandleR)
{
	Handle.P->RegObject(Key, &Object);
	HandleR = Handle;
}