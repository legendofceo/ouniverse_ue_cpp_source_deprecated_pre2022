// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Win.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FWinDelegate);

UCLASS()
class APP_API AWin : public AActor
{
	GENERATED_BODY()

public:

	AWin();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	AWin* WinParent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	AWin* WinChild;

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void BeginOpenWin();

	UFUNCTION(BlueprintImplementableEvent)
	void BeginCloseWin();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void BeginChangeWin();
	virtual void BeginChangeWin_Implementation();

	UPROPERTY(BlueprintAssignable)
	FWinDelegate OnCloseWinInterrupted;

	UPROPERTY(BlueprintAssignable)
	FWinDelegate OnCloseWinComplete;

	UPROPERTY(BlueprintAssignable)
	FWinDelegate OnCloseWinBaton;

	UFUNCTION(BlueprintCallable)
	void CloseWinInterrupted()
	{
		OnCloseWinInterrupted.Broadcast();
	}


	UFUNCTION(BlueprintCallable)
	void CloseWinComplete()
	{
		OnCloseWinComplete.Broadcast();
	}

	UFUNCTION(BlueprintCallable)
	void CloseWinBaton()
	{
		OnCloseWinBaton.Broadcast();
	}


	UFUNCTION()
	void BeginConcludeWin();

};