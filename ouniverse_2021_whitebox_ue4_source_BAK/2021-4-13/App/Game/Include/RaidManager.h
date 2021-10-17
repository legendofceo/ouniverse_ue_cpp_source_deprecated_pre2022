// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "RaidManager.generated.h"


struct FRaid;

class UPartyHandle;

UCLASS()
class APP_API URaidManager : public UObject
{
	GENERATED_BODY()

public:

	void Init();

	FRaid* RaidData;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TArray<UPartyHandle*> Parties;

	void Connect(FRaid* InRaidData);
};
