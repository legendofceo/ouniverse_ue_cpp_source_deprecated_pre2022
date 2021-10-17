// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Execs.generated.h"


UENUM(BlueprintType)
enum class EYesNo : uint8
{
	Yes,
	No,
};

UENUM(BlueprintType)
enum class ESuccess : uint8
{
	Success,
	Fail,
};