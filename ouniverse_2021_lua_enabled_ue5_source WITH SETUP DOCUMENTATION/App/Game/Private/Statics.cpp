// Fill out your copyright notice in the Description page of Project Settings.


#include "Statics.h"
#include "AppWorld.h"
#include "Blueprint/UserWidget.h"

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








bool UStatics::HasFunctionBP(UObject* Obj, FName FunctionName)
{
	UFunction* function = Obj->FindFunction(FunctionName);

	if (function != NULL)
	{
		FString name = function->GetName();
		bool b = function->IsInBlueprint();
		if (b)
		{
			return true;
		}
	}

	return false;
}






void UStatics::HotParamObject(UObject*& Param, TSoftClassPtr<UObject> Soft)
{
	Param = NewObject<UObject>(UAppWorld::GetAppWorld(), Soft.Get());
}

void UStatics::HotParamWidget(UUserWidget*& Param, TSoftClassPtr<UUserWidget> Soft)
{
	Param = CreateWidget<UUserWidget>(UAppWorld::GetAppWorld(), Soft.Get());
}

void UStatics::SoftToObject(TSoftClassPtr<UObject> Soft, UObject*& R)
{
	R = NewObject<UObject>(UAppWorld::GetAppWorld(), Soft.Get());
}


void UStatics::ForceObjectParam(UObject* Object, UObject*& Param, UObject*& R)
{
	Param = Object;
	R =  Object;
}