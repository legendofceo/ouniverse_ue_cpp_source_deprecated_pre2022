// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Tally.generated.h"



USTRUCT()
struct APP_API FTally
{
	GENERATED_BODY()

public:

	UPROPERTY(VisibleAnywhere)
	bool bComplete = false;

	UPROPERTY(VisibleAnywhere)
	TSet<int> TIDs;

	void Reset()
	{
		bComplete = false;
		TIDs.Reset();
	}

	void Add(int TID)
	{
		TIDs.Add(TID);
	}

	bool Complete(int TID)
	{
		TIDs.Remove(TID);
		if (TIDs.Num() == 0)
		{
			bComplete = true;
		}

		return bComplete;
	}

};