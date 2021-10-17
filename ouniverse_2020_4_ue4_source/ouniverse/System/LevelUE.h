// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"
#include "LevelUE.generated.h"

class AActor;


UCLASS()
class OUNIVERSE_API ALevelUE : public ALevelScriptActor
{
	GENERATED_BODY()
	
public:

	UPROPERTY(BlueprintReadWrite,EditAnywhere)
	TMap<FString, AActor*> EntrySequences;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TMap<int, int> LevelFlags;

	UFUNCTION(BlueprintCallable,BlueprintPure)
	AActor* GetEntrySequence(FString BTN) { return NULL; };

};
