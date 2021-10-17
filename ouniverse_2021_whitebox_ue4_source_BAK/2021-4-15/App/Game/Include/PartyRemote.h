// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Remote.h"
#include "PartyRemote.generated.h"

class UPartyPro;

UCLASS(BlueprintType, Blueprintable)
class APP_API UPartyRemote : public URemote
{
	GENERATED_BODY()

public:

	UPartyRemote();

	void Init(AAppController* AP, UPartyPro* InPartyPro);

	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UPartyPro* PartyPro;

	void Engage();
};
