// Fill out your copyright notice in the Description page of Project Settings.


#include "Context.h"
#include "AGS.h"

UObject* UContext::Get()
{
	return AGS::GetGS();
}