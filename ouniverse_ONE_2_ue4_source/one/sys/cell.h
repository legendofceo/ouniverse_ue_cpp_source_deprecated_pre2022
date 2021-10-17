// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelStreamingDynamic.h"
#include "base.h"
#include "cell.generated.h"

class ULevelStreamingDynamic;
class ALevelCell;
class AArea;



UCLASS()
class ACell: public ABase
{

	GENERATED_BODY()

public:

	ACell();

	static ACell* Create(AArea* InArea, FName InCatalyst);

	UPROPERTY(Category = Cell, VisibleAnywhere, BlueprintReadOnly)
	AArea* Area;

	UPROPERTY(Category = Cell, VisibleAnywhere, BlueprintReadOnly)
	FName Catalyst;

	UFUNCTION(BlueprintCallable, Category = Cell)
	void Load();

	UFUNCTION(BlueprintCallable, Category = Cell)
	void OnLevelStreamed();

	UFUNCTION(BlueprintCallable, Category = Cell)
	void Unload();

	UPROPERTY(Category = Cell, VisibleAnywhere, BlueprintReadOnly)
	ULevelStreamingDynamic* StreamedLevel_;

	UPROPERTY(Category = Cell, VisibleAnywhere, BlueprintReadOnly)
	ALevelCell* Level;

	UPROPERTY(Category = Cell, VisibleAnywhere, BlueprintReadOnly)
	bool bLoaded;


};