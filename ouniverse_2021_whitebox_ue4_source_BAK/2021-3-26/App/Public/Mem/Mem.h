// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Mem/PlaythroughMem.h"
#include "Mem.generated.h"

USTRUCT(BlueprintType)
struct FMemState
{
    GENERATED_BODY()

public:

    FMemState();

    void Restart();

//Stories

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FPlaythroughMem Playthrough;

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

};