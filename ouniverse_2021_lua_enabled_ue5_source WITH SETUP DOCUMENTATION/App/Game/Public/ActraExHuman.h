// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ActraEx.h"
#include "ActraExHuman.generated.h"


class UActraMemHuman;
class UChassis;
class UBehaviorHuman;

UCLASS(Abstract, BlueprintType, Blueprintable)
class APP_API AActraExHuman : public AActraEx
{
	GENERATED_BODY()

public:

	AActraExHuman();

	virtual void BeginInit() override;
	UFUNCTION()
	void Init_Steps(int Step);

	UPROPERTY(VisibleAnywhere)
	UActraMemHuman* ActraMemHuman;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UChassis* Chassis;

	UPROPERTY(VisibleAnywhere)
	UBehaviorHuman* BehaviorHuman;

	void Connect() override;

};