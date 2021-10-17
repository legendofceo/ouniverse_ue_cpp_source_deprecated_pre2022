// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Behavior.h"
#include "BehaviorHuman.generated.h"


class AActraExHuman;
class UKitRove;

UCLASS(Blueprintable,BlueprintType)
class APP_API UBehaviorHuman : public UBehavior
{
	GENERATED_BODY()
	
public:

	void Init(AActraExHuman* InActraExHuman);

	UPROPERTY(VisibleAnywhere)
	AActraExHuman* ActraExHuman;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UKitRove* KitRove;

	void Connect() override;
	void Disconnect() override;

};
