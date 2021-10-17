// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Protocol.h"
#include "Log.h"
#include "PartyPro.generated.h"


UCLASS(BlueprintType, Blueprintable)
class APP_API UPartyPro : public UProtocol
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UPartyPro();

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FLogger Log;

	static UPartyPro* Get();

	void Init();

};
