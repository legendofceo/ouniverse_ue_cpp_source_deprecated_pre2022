// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AreaAddress.generated.h"

class UArea;


USTRUCT(BlueprintType)
struct FAddress
{
	GENERATED_BODY()

public:


	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FName Address;

	FAddress() {};
};

USTRUCT(BlueprintType)
struct FAreaAddress
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UArea* Area;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FAddress Address;


	FAreaAddress()
	{
		Area = NULL;
	}

	FAreaAddress(UArea* InArea, FAddress InAddress)
	{
		if (Area != NULL)
		{
			Area = InArea;
			Address = InAddress;
		}
		else
		{
			Area = NULL;
		}
	}

	bool IsValid();
	void Invalidate();

};

UCLASS()
class APP_API UAreaAddressUtil : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "#AreaAddress"))
	static void MakeAreaAddress(UArea* Area, FAddress Address, FAreaAddress& AreaAddress);

};