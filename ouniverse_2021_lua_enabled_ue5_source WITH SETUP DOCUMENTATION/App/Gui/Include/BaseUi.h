// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Delegate.h"
#include "CommandMenuInterface.h"
#include "BaseUi.generated.h"

class UBT;
class UPanelWidget;

UCLASS(Abstract)
class APP_API UBaseUi : public UUserWidget, public ICommandMenuInterface
{
	GENERATED_BODY()

public:


	UFUNCTION(BlueprintCallable, meta = (DisplayName = "#Open"))
	void DoOpen();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "#OpenCB"))
	void DoOpenCB(const FDelDynamic& Event);

	void Open(FDelBasic OnCloseComplete);

	UFUNCTION(BlueprintNativeEvent, meta = (DisplayName = "#BeginOpen"))
	void BeginOpen();
	virtual void BeginOpen_Implementation();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "#OpenComplete"))
	void OpenComplete();

	FDelBasic OpenCompleteCB;


	UFUNCTION(BlueprintCallable, meta = (DisplayName = "#Close"))
	void DoClose(const FDelDynamic& Event);

	void Close(FDelBasic OnCloseComplete);

	UFUNCTION(BlueprintNativeEvent, meta = (DisplayName = "#BeginClose"))
	void BeginClose();
	virtual void BeginClose_Implementation();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "#CloseComplete"))
	void CloseComplete();

	FDelBasic CloseCompleteCB;

};