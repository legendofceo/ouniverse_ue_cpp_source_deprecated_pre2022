// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "InputScalar.generated.h"


UCLASS(Blueprintable,BlueprintType)
class APP_API UInputScalar : public UObject
{
	GENERATED_BODY()

public:


	FTimerHandle TimerHandle;

	UFUNCTION()
	void TimerTick();

	void Connect();
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "#Connect"))
	void ConnectBP();

	void Disconnect();
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "#Disconnect"))
	void DisconnectBP();

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	bool bConnected;

	UPROPERTY(VisibleAnywhere)
	FName ID;

	void Sync(bool PlusPress, bool NegPress);


	void PlusPress();
	void PlusRelease();
	UFUNCTION(BlueprintCallable,meta=(DisplayName="#Plus"))
	void PlusBP(bool Press);

	void MinusPress();
	void MinusRelease();
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "#Minus"))
	void MinusBP(bool Press);

	void ComputeRawPower();

	float GetPower();

	UPROPERTY(VisibleAnywhere)
	float RawPower;

	float ResultPower;

	UPROPERTY(VisibleAnywhere)
	bool bPositivePressed;
	UPROPERTY(VisibleAnywhere)
	bool bNegativePressed;
};