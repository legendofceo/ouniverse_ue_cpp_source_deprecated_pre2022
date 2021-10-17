// Fill out your copyright notice in the Description page of Project Settings.


#include "Index.h"


FIndex::FIndex(int Start, int Min, int Max)
{
	MinValue = Min;
	MaxValue = Max;
	Set(Start);
}

void FIndex::Set(int NewValue)
{
	Value = NewValue;

	if (Value > MaxValue)
	{
		Value = MaxValue;
	}

	if (Value < MinValue)
	{
		Value = MinValue;
	}
}

int FIndex::Get()
{
	return Value;
}

void FIndex::Increment()
{
	if (Value == MaxValue)
	{
		Value = MinValue;
	}
	else
	{
		Value++;
	}
}


void FIndex::Decrement()
{
	if (Value == MinValue)
	{
		Value = MaxValue;
	}
	else
	{
		Value--;
	}
}

void FIndex::Push(bool bReverse)
{
	if (bReverse)
	{
		Decrement();
	}
	else
	{
		Increment();
	}
}




void UIndexStatics::Push(FIndex& Indexer, bool bReverse, int& R)
{
	Indexer.Push(bReverse);
	R = Indexer.Value;
}

void UIndexStatics::Increment(FIndex& Indexer, int& R)
{
	Indexer.Increment();
	R = Indexer.Value;
}

void UIndexStatics::Decrement(FIndex& Indexer, int& R)
{
	Indexer.Decrement();
	R = Indexer.Value;
}

void UIndexStatics::Get(FIndex& Indexer, int& R)
{
	R = Indexer.Value;
}

void UIndexStatics::Set(FIndex& Indexer, int Value, int& R)
{
	Indexer.Set(Value);
	R = Indexer.Value;
}

void UIndexStatics::SetMax(FIndex& Indexer, int NewMax)
{
	Indexer.MaxValue = NewMax;
}