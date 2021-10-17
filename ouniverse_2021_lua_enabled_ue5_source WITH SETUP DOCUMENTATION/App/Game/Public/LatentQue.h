// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LatentQue.generated.h"


USTRUCT(Blueprintable, BlueprintType)
struct APP_API FLatentQue
{
	GENERATED_BODY()

public:

	UPROPERTY(VisibleAnywhere)
		int Que = 0;

	void Reset() { Que = 0; };

	bool ReplyCompletes()
	{
		Que--;

		if (Que == 0)
		{
			return true;
		}

		return false;
	}

	FLatentQue& operator++() {
		Que++;
		return *this;
	}

	FLatentQue operator++(int) {
		FLatentQue temp = *this;
		++* this;
		return temp;
	}
};