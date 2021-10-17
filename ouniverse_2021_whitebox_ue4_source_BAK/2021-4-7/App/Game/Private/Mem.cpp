// Fill out your copyright notice in the Description page of Project Settings.


#include "Mem.h"


UMem::UMem()
{

}

void UMem::RegBool(FString MarshalKey, bool& Bool)
{
	Marshal.AddBool(MarshalKey, &Bool);
}