// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Director.generated.h"

class UAct;

UCLASS()
class OUNIVERSE_API UDirector : public UObject
{

	GENERATED_BODY()

public:

	UDirector();
	static UDirector* Get();
	static UDirector* Create(TMap<FName, TSoftClassPtr<UAct>>* InActReg);

	void Init(TMap<FName, TSoftClassPtr<UAct>>* InActReg);

	UAct* Act_;

	void SetAct(FName ActID);

	TMap<FName, TSoftClassPtr<UAct>>* ActReg_;
};