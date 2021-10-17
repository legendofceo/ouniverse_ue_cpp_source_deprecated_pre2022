// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Delegate.h"
#include "Protocol.generated.h"


UCLASS()
class APP_API UProtocol : public UObject
{
	GENERATED_BODY()
	
public:	

	UProtocol();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool bInit;

	void InitComplete();

	UPROPERTY()
	FDelegateObj OnInitComplete;

};
