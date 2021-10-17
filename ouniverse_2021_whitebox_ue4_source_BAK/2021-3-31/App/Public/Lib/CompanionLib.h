// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Lib/Lib.h"
#include "CompanionLib.generated.h"


class UCompanion;

UCLASS(Abstract, BlueprintType, Blueprintable)
class APP_API UCompanionLib : public ULib
{
	GENERATED_BODY()

public:

	static UCompanionLib* Get();

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = ":CompanionMng"))
	static void GetCompanionMngBP(UCompanionLib*& CompanionMng);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TMap<int, UCompanion*> Companions;

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "#RegCompanion"))
	void RegCompanion(TSoftClassPtr<UCompanion> CompanionClass, FString MarshalKey, UPARAM(ref) UCompanion*& Param);

	UFUNCTION(BlueprintCallable,BlueprintPure,meta=(DisplayName = "#CompanionSCP"))
	void CompanionSCP(TSoftClassPtr<UCompanion>C, TSoftClassPtr<UCompanion>& R);

	void Init() override;
	void PostAsync() override;

};
