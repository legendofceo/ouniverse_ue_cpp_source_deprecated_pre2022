// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Hero.generated.h"

/**
 * 
 */


USTRUCT(BlueprintType)
struct FHeroTable : public FTableRowBase
{
    GENERATED_BODY()
public:

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        FText Name;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        FText Native;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        FText Subtitle;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        FText Medium;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        int Plus;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        UTexture2D* Icon;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        UTexture2D* IconLarge;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        FText Description;



};

UCLASS()
class APP_API UHero : public UObject
{
	GENERATED_BODY()
	
};
