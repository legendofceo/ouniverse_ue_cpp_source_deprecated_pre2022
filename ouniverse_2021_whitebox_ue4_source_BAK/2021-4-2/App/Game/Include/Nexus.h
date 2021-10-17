// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Info.h"
#include "Delegate.h"
#include "Marshal.h"
#include "Log.h"
#include "Nexus.generated.h"

/**
 * 
 */
UCLASS()
class APP_API ANexus : public AInfo
{
	GENERATED_BODY()
	
public:

	ANexus();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool bInit = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FMarshal Marshal;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FLogger Log;

	UPROPERTY(BlueprintAssignable)
	FDelegateObj OnInitComplete;

};