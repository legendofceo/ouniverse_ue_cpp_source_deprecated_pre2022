// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Lib/Lib.h"
#include "AreaLib.generated.h"

class UArea;

UCLASS(Abstract, BlueprintType, Blueprintable)
class APP_API UAreaLib : public ULib
{
	GENERATED_BODY()

public:

	static UAreaLib* Get();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TMap<int, UArea*> Areas;

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "#RegArea"))
	void RegArea(TSoftClassPtr<UArea> AreaClass, FString MarshalKey, UPARAM(ref) UArea*& Param);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "#AreaSCP"))
	void AreaSCP(TSoftClassPtr<UArea>C, TSoftClassPtr<UArea>& R);

	void Init() override;
	void PostAsync() override;

};
