// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "data_address.generated.h"

class ActraD;

#define Area_FATA(VAR, ADDRESS) DataFetch<AreaD*, ActraLib*> VAR = DataFetch<AreaD*, ActraLib*>(ADDRESS);


USTRUCT(BlueprintType)
struct FDataAddress
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	int32 PackUN;

	UPROPERTY(EditAnywhere)
	int32 DataUN;

	FDataAddress()
	{
		Null();
	}

	void Empty()
	{
		PackUN = 0;
		DataUN = 0;
	}

	bool IsEmpty()
	{
		if (PackUN == 0)
		{
			return true;
		}

		return false;
	}

	void Null()
	{
		PackUN = -2147483647;
		DataUN = -2147483647;
	}

	bool IsNull()
	{
		if (PackUN == -2147483647)
		{
			return true;
		}

		return false;
	}

	FDataAddress(int32 Pack, int32 Form)
	{
		PackUN = Pack;
		DataUN = Form;
	}

	void SetPack(int32 InPack)
	{
		PackUN = InPack;
	}


	void SetForm(int32 InData)
	{
		DataUN = InData;
	}

	int Pack()
	{
		return PackUN;
	}

	int Form()
	{
		return DataUN;
	}

	operator FString() const 
	{ 
		return FString::FromInt(PackUN)+"."+ FString::FromInt(DataUN);
	}

	operator const TCHAR*() const
	{
		return *FString(FString::FromInt(PackUN) + "." + FString::FromInt(DataUN));
	}

};