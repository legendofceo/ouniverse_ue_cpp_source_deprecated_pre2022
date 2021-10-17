// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "StoryMem.h"
#include "CompanionMem.h"
#include "PlaythroughMem.generated.h"

/**
 * 
 */

struct FStoryMem;
struct FCompanionMem;

USTRUCT(BlueprintType)
struct FPlaythroughMem
{
	GENERATED_BODY()

public:

    FPlaythroughMem();

	UPROPERTY(VisibleANywhere, BlueprintReadWrite)
	int ActiveStory;

    UPROPERTY(VisibleANywhere, BlueprintReadWrite)
    TMap<int, FStoryMem> Stories;

    FStoryMem* AddStoryMem(int Key);

    FStoryMem* GetStoryMem(int Key);

    //Companions

    UPROPERTY(VisibleANywhere, BlueprintReadWrite)
    TMap<int, FCompanionMem> Companions;

    FCompanionMem* GetCompanionMem(int Key);

    FCompanionMem* AddCompanionMem(int Key);

};