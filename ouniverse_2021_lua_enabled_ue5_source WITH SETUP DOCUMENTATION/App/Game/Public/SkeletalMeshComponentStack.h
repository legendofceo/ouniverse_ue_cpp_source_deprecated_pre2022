// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Array.h"
#include "SkeletalMeshComponentStack.generated.h"

class USkeletalMeshComponent;


USTRUCT()
struct APP_API FSkeletalMeshComponentStack
{
	GENERATED_BODY()

public:

	FSkeletalMeshComponentStack()
	{

	}

	ArrayC<USkeletalMeshComponent**> Stack;

	void Reg(USkeletalMeshComponent** SMC);

	void Add(USkeletalMeshComponent* SMC);

	USkeletalMeshComponent** NextAvailable();
};