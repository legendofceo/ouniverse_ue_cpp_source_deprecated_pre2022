// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Delegate.h"
#include "Marshal.h"
#include "Log.h"
#include "Annex.generated.h"


UCLASS()
class APP_API UAnnex : public UObject
{
	GENERATED_BODY()
	
public:

	UAnnex();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool bInit = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FMarshal Marshal;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FLogger Log;

	UPROPERTY(BlueprintAssignable)
	FDelegateObj OnInitComplete;

};