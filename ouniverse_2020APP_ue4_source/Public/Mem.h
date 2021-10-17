// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Mem.generated.h"

/**
 * 
 */

class UMemHero;
class UMemActra;
class UMemArea;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ETREIAAPP_API UMem : public UActorComponent
{
	GENERATED_BODY()

	
public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TArray<UMemHero*> Hero;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TArray<UMemActra*> Actra;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TArray<UMemArea*> Area;
};
