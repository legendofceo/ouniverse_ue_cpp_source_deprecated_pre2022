// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Remote.h"
#include "SpectatorRemote.generated.h"


class UPartyPro;
class USpectatorUi;

UCLASS(BlueprintType, Blueprintable)
class APP_API USpectatorRemote : public URemote
{
	GENERATED_BODY()

public:

	USpectatorRemote();

	UFUNCTION(NetMulticast, Reliable)
	void Init(AAppController* AP, UPartyPro* InPartyPro);

	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UPartyPro* PartyPro;

	void Engage_SERVER();

	UFUNCTION(Client, Reliable)
	void Engage_CLIENT();

	UFUNCTION()
	void Ui_AsyncLoad();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	USpectatorUi* Ui;
};
