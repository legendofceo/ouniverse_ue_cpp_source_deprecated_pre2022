// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Chapter.generated.h"


UCLASS(Blueprintable)
class OUNIVERSE_API UChapter : public UObject
{
	GENERATED_BODY()

public:

	UChapter();

	static UChapter* Create();

};