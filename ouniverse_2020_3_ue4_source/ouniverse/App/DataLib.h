// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Interface/Map.h"

#include "DataLib.generated.h"

class DataPackC;
class DataD;

UCLASS()
class OUNIVERSE_API UDataLib : public UObject
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
	static void Test();

};


class DataLibC
{

public:

	DataLibC();

	static DataLibC* Get();

	bool TryData(int InPack, int InData, DataD*& InRef);

private:

	MapC<int, DataPackC*> Lib_;
};