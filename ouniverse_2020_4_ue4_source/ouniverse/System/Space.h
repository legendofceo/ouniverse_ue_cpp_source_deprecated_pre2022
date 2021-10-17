// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelStreamingDynamic.h"
#include "Space.generated.h"


USTRUCT(BlueprintType)
struct OUNIVERSE_API FAddress
{
	GENERATED_BODY()

public:

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Test")
		int DLC;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Test")
		FName Area;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Test")
		FName Catalyst;

		FAddress()
		{

		}

		FAddress(int InDLC, FName InArea, FName InCatalyst)
		{
			DLC = InDLC;
			Area = InArea;
			Catalyst = InCatalyst;
		}

		FSoftClassPath AsAreaClass()
		{
			return FSoftClassPath("/Game/dlc/" + FString::FromInt(DLC) + "/" + Area.ToString() + "." + Area.ToString() + "_C");

		}
};

UCLASS()
class OUNIVERSE_API USpace : public UObject
{

	GENERATED_BODY()

public:

	USpace();
	static USpace* Get();
	static USpace* Create();


	void LoadDestination(FAddress InDestination);
};