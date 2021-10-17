// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UObject/Object.h"
#include "UObject/SoftObjectPtr.h"
#include "ico_manager.generated.h"

class UIco_U;

UCLASS(Abstract,Blueprintable)
class UIcoManager : public UObject
{
	GENERATED_BODY()

public:
	
	UIcoManager() {};
	static UIcoManager* Create(TSoftClassPtr<UIcoManager> SoftClass, UObject* WorldCTX);
	static UIcoManager* Get();

	UPROPERTY(Category = "0 Details", EditAnywhere, BlueprintReadOnly)
	TSoftClassPtr<UIco_U>  DefaultIco;

	UPROPERTY(Category="0 Details", EditAnywhere, BlueprintReadOnly)
	TMap<int32, TSoftClassPtr<UIco_U>> Lib;

	TSoftClassPtr<UIco_U> FindOrDefault(int32 InID);

};