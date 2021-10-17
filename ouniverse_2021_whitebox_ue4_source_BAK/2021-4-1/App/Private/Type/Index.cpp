// Fill out your copyright notice in the Description page of Project Settings.


#include "Type/Index.h"

UIndexByte*  UIndexByte::CreateIndexByte(uint8 MinValue, uint8 MaxValue, uint8 StartValue)
{
	UIndexByte* NewIndex = NewObject<UIndexByte>();
	NewIndex->Min = MinValue;
	NewIndex->Max = MaxValue;
	NewIndex->SetValue(StartValue);
	return NewIndex;
}

uint8 UIndexByte::IncrementValue(bool bReverse)
{
	if (bReverse)
	{
		if (Value == Min)
		{
			Value = Max;
		}
		else
		{
			Value--;
		}
	}
	else
	{
		if (Value == Max)
		{
			Value = Min;
		}
		else
		{
			Value++;
		}
	}
	return Value;
}

uint8 UIndexByte::SetValue(uint8 NewValue)
{
	Value = NewValue;

	if (Value > Max)
	{
		Value = Max;
	}

	if (Value < Min)
	{
		Value = Min;
	}

	return Value;
}
