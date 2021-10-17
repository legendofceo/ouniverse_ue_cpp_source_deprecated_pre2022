// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "StoryMem.h"
#include "CompanionMem.h"
#include "Mem.generated.h"

USTRUCT(BlueprintType)
struct FMemState
{
    GENERATED_BODY()

public:

    FMemState();

    void Restart();

//Stories

    UPROPERTY(VisibleANywhere, BlueprintReadWrite)
    TMap<int, FStoryMem> Stories;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TMap<FName, bool> Bools;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TMap<FName, uint8> Bytes;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TMap<FName, int> Ints;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TMap<FName, float> Floats;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TMap<FName, FString> Strings;

    FStoryMem* AddStoryMem(int Key);

    FStoryMem* GetStoryMem(int Key);

//Companions

    UPROPERTY(VisibleANywhere, BlueprintReadWrite)
    TMap<int,FCompanionMem> Companions;

    FCompanionMem* GetCompanionMem(int Key);

    FCompanionMem* AddCompanionMem(int Key);

    UPROPERTY(VisibleANywhere, BlueprintReadWrite)
    int ActiveStory;

};