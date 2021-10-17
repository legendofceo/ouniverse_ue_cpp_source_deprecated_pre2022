// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "MemTable.generated.h"


USTRUCT(BlueprintType)
struct FMemBoolsTable : public FTableRowBase
{
	GENERATED_BODY()
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool Default;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Purpose;

};

USTRUCT(BlueprintType)
struct FMemBytesTable : public FTableRowBase
{
	GENERATED_BODY()
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	uint8 Default;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Purpose;

};
