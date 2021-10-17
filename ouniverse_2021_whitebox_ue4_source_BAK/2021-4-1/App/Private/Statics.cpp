// Fill out your copyright notice in the Description page of Project Settings.


#include "Statics.h"

FTransform UStatics::EmptyTransform()
{
	return FTransform();
}

void UStatics::Limbo(FTransform& XForm)
{
	XForm =  FTransform();
}

uint8 UStatics::IncrementByteBP(uint8 Byte, bool bDecrement, uint8 Min, uint8 Max, ENumericOverflowMethodParam OverflowMethod)
{
	if (bDecrement)
	{
		if (Byte == Min)
		{
			Byte = Max;
		}
		else
		{
			Byte--;
		}
	}
	else
	{
		if (Byte == Max)
		{
			Byte = Min;
		}
		else
		{
			Byte++;
		}
	}
	return Byte;
}

void UStatics::PlaceActorsAtActor(TArray<AActor*> Actors, AActor* Target, float RotateRandom, FVector TranslateRandom, ESpawnFormation Formation)
{
	for (AActor* Actor : Actors)
	{
		Actor->SetActorLocation(Target->GetActorLocation());
	}
}