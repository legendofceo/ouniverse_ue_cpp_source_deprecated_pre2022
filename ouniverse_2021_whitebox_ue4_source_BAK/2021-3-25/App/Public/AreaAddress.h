// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AreaAddress.generated.h"

class UArea;


USTRUCT(BlueprintType)
struct FAreaAddress
{
	GENERATED_BODY()

public:
		
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSoftClassPtr<UArea> Area;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FName Address;

	FAreaAddress()
	{
		Area = NULL;
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
	static void MakeAreaAddress(TSoftClassPtr<UArea> Area, FName Address, FAreaAddress& AreaAddress);

};