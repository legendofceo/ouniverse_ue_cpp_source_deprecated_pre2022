// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "level_ue.h"
#include "level_cell.generated.h"

class ACell;
class AArea;

UCLASS()
class ALevelCell : public ALevelUE
{
	GENERATED_BODY()
	
public:

	UPROPERTY(Category = LevelCell, VisibleAnywhere, BlueprintReadOnly)
	ACell* Cell;

	UPROPERTY(Category = LevelCell, VisibleAnywhere, BlueprintReadOnly)
	AArea* Cosm;

	void Start(AArea* InCosm, FName SparkCode);

	UFUNCTION(BlueprintImplementableEvent)
	void OnStart(FName SparkCode);

};