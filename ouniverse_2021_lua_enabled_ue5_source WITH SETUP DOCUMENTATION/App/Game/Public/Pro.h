// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ObjectPlus.h"
#include "Delegate.h"
#include "Pro.generated.h"



UCLASS(Abstract,BlueprintType,Blueprintable)
class APP_API UPro : public UObjectPlus
{
	GENERATED_BODY()

public:


	UFUNCTION(BlueprintCallable, meta = (DisplayName = "#Engage"))
	void DoEngage();

	void Engage();

	UFUNCTION(BlueprintNativeEvent, meta = (DisplayName = "#BeginEngage"))
	void BeginEngage();
	virtual void BeginEngage_Implementation();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "#Disengage"))
	void DoDisengage(const FDelDynamic& Event);

	void Disengage(FDelBasic OnDisengageComplete);

	UFUNCTION(BlueprintNativeEvent, meta = (DisplayName = "#BeginDisengage"))
	void BeginDisengage();
	virtual void BeginDisengage_Implementation();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "#DisengageComplete"))
	void DisengageComplete();

	FDelBasic DisengageCompleteCB;

};