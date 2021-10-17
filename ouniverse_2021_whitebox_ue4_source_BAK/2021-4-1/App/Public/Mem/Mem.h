// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Marshal/Marshal.h"
#include "Mem.generated.h"


UCLASS(Abstract, BlueprintType, Blueprintable)
class APP_API UMem : public UObject
{
	GENERATED_BODY()
	
public:

	UMem();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FMarshal Marshal;

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "#RegBool"))
	void RegBool(FString MarshalKey, UPARAM(ref) bool& Bool);

};