// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TockBoxUi.generated.h"


class UHorizontalBox;

UCLASS()
class APP_API UTockBoxElementUi : public UUserWidget
{
	GENERATED_BODY()

};


UCLASS()
class APP_API UTockBoxHorizontalUi : public UUserWidget
{
	GENERATED_BODY()


public:

	UPROPERTY(VisibleAnywhere)
	int Index;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	int ElementSize;
	
	UPROPERTY(EditAnywhere)
	int SideUnits;

	UFUNCTION(BlueprintCallable,meta=(DisplayName="#Build"))
	void Build();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "#Build"))
	void AddElement(UTockBoxElementUi* Element);

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UHorizontalBox* Box;

	UPROPERTY(VisibleAnywhere)
	TArray<UTockBoxElementUi*> Elements;

	UPROPERTY(VisibleAnywhere)
	TArray<UTockBoxElementUi*> ActiveSlots;

	UPROPERTY(EditAnywhere)
	float ShiftTime;

	UPROPERTY(VisibleAnywhere)
	bool bShifting;

	UPROPERTY(VisibleAnywhere)
	bool bShiftReverse;

	UPROPERTY(VisibleAnywhere)
	float ShiftDelta;

	void ShiftRight();

	void ShiftLeft();

	void BeginShift();

	UFUNCTION()
	bool Shift(float Delta);

	FTickerDelegate TickDelegate;
	FDelegateHandle TickDelegateHandle;
};