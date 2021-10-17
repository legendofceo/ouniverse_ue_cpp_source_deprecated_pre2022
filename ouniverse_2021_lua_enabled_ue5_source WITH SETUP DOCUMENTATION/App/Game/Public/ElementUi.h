// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Delegate.h"
#include "ElementUi.generated.h"


UCLASS(Abstract)
class APP_API UElementUi : public UUserWidget
{
	GENERATED_BODY()

public:


	UFUNCTION(BlueprintCallable, meta = (DisplayName = "#Engage"))
	void DoEngage();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "#EngageCB"))
	void DoEngageCB(const FDelDynamic& Event);

	void Engage(FDelBasic OnEngageComplete);

	UFUNCTION(BlueprintNativeEvent, meta = (DisplayName = "#BeginEngage"))
	void BeginEngage();
	virtual void BeginEngage_Implementation();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "#EngageComplete"))
	void EngageComplete();

	FDelBasic EngageCompleteCB;


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